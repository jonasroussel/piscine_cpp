#include <ncurses.h>
#include <iostream>
#include <chrono>

#include "map.hpp"
#include "consts.hpp"

#include "class/IEntity.hpp"
#include "class/Player.hpp"
#include "class/Enemy.hpp"
#include "class/ProjectileManager.hpp"
#include "class/Laser.hpp"
#include "class/Rocket.hpp"
#include "class/HyenaBomber.hpp"
#include "class/StarFighter.hpp"

#define DIFF 4

int	ft_mov(Map m, Player * p1)
{
	int	tou;

	tou = getch();
	attron(COLOR_PAIR(PLAYER));
	if (tou == 97 && p1->getX() > 1)
	{
		move(p1->getY(), p1->getX());
		printw(" ");
		p1->move(-1);
	}
	if (tou == 100 && p1->getX() < m.lmax - 3)
	{
		move(p1->getY(), p1->getX());
		printw(" ");
		p1->move(1);
	}
	attroff(COLOR_PAIR(PLAYER));
	return (tou);
}

void	init_arena(Map m)
{
	WINDOW *win;

	initscr();
	start_color();
	init_pair(PLAYER,COLOR_GREEN, COLOR_BLACK);
	init_pair(ENEMY, COLOR_WHITE, COLOR_BLACK);
	init_pair(LASER, COLOR_RED, COLOR_BLACK);
	init_pair(SPACE, COLOR_WHITE, COLOR_BLACK);
	init_pair(SCORE, COLOR_WHITE, COLOR_BLUE);
	init_pair(NAME, COLOR_BLACK, COLOR_GREEN);
	init_pair(TREE, COLOR_BLACK, COLOR_WHITE);
	init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
	srand(time(NULL));
	nodelay(stdscr, true);
	noecho();
	attron(COLOR_PAIR(SPACE));
	win= subwin(stdscr, m.cmax, m.lmax, 0, 0);
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
	attroff(COLOR_PAIR(SPACE));
	curs_set(0);
	wrefresh(win);
}

void	Enemygen(int ch, Player * p1, ProjectileManager & pm)
{
	int		rng;
	int		i = 0;
	Enemy	tmp;
	static int	index;
	static Enemy * enn = new Enemy[MAX_EN];

	rng = rand() % 100;
	if (rng < ch && index < MAX_EN)
	{
		rng = rand() % 3;
		
		if (rng == 2)
			enn[index] = HyenaBomber();
		else if (rng == 1)
			enn[index] = StarFighter();
		else
			enn[index] = Enemy();

		rng = (rand() % (WIDTH - 4));
		enn[index].setXY(rng + 2 , 2);
		index++;
	}
	i = 0;
	while (i < index)
	{
		if (enn[i].getY() == p1->getY() && enn[i].getX() == p1->getX())
			p1->takeDamage(p1->getHP());

		attron(COLOR_PAIR(ENEMY));
		move(enn[i].getY() - 1, enn[i].getX());
		printw(" ");
		move(enn[i].getY(), enn[i].getX());
		printw(" ");
		enn[i].clock();
		pm.shoot(enn + i, enn[i].getX(), enn[i].getY() + 1, enn[i].getDY(), 'e');
		if (enn[i].getY() > HEIGHT - 3)
		{
			move(enn[i].getY(), enn[i].getX());
			printw(" ");
			enn[i] = enn[index - 1];
			enn[index--].~Enemy();
		}
		else
		{
			enn[i].move();
			move(enn[i].getY(), enn[i].getX());
			addch(enn[i].getSymbol());
		}
		i++;

		if (enn[i].getY() == p1->getY() && enn[i].getX() == p1->getX())
			p1->takeDamage(p1->getHP());
	}

	pm.update(&index, &enn, p1);

	attroff(COLOR_PAIR(ENEMY));
	(void)p1;
}

void	ft_score(Player p)
{
	attron(COLOR_PAIR(NAME));
	move(0, (WIDTH / 2) - 12);
	printw("  MEPHISTO'S ADVENTURE  ");
	attroff(COLOR_PAIR(SPACE));
	attron(COLOR_PAIR(SCORE));
	move(HEIGHT, WIDTH * 0.2);
	printw(" HP: %3d ", p.getHP());
	move(HEIGHT, WIDTH * 0.6);
	printw(" SCORE: %3d ", p.getScore());

	attroff(COLOR_PAIR(SCORE));
}

void	ft_tree()
{
	int				rng;
	int				i = 0;
	static Enemy * tree = new Enemy[10];
	static	int		index;

	rng = rand() % 500;
	if (rng < 5 && index < 2)
	{
		rng = (rand() % (WIDTH - 10));
		tree[index] = Enemy();
		tree[index].setXY(rng + 5, 2);
		tree[index++].setDY(1);
	}
	while (i < index)
	{
		attron(COLOR_PAIR(BLACK));
		if (tree[i].getX() - 2 > 2 && tree[i].getY() < HEIGHT + 1)
		{
			move(tree[i].getY() - 2, tree[i].getX());
			printw("u");
		}
		if (tree[i].getY() - 1 > 2 && tree[i].getY() < HEIGHT)
		{
			move(tree[i].getY() - 1, tree[i].getX() - 1);
			printw("***");
		}
		if (tree[i].getY() < HEIGHT - 1)
		{
			move(tree[i].getY(), tree[i].getX() - 2);
			printw("*****");
		}
		if (tree[i].getY() + 1 < HEIGHT - 1)
		{
			move(tree[i].getY() + 1, tree[i].getX() - 1);
			printw("***");
		}
		if (tree[i].getY() + 2 < HEIGHT - 1)
		{
			move(tree[i].getY() + 2, tree[i].getX());
			printw("*");
		}
			attron(COLOR_PAIR(BLACK));
		tree[i].clock();
		if (tree[i].getY() < HEIGHT + 3)
		{
			tree[i].move();
			attron(COLOR_PAIR(TREE));
			if (tree[i].getX() - 2 > 2 && tree[i].getY() < HEIGHT + 1)
			{
				move(tree[i].getY() - 2, tree[i].getX());
				printw(" ");
			}
			if (tree[i].getY() - 1 > 2 && tree[i].getY() < HEIGHT)
			{
				move(tree[i].getY() - 1, tree[i].getX() - 1);
				printw("O o");
			}
			if (tree[i].getY() < HEIGHT - 1)
			{
				move(tree[i].getY(), tree[i].getX() - 2);
				printw("O o  ");
			}
			if (tree[i].getY() + 1 < HEIGHT - 1)
			{
				move(tree[i].getY() + 1, tree[i].getX() - 1);
				printw("  o");
			}
			if (tree[i].getY() + 2 < HEIGHT - 1)
			{
				move(tree[i].getY() + 2, tree[i].getX());
				printw(" ");
			}
			attroff(COLOR_PAIR(TREE));
		}
		else
		{
			tree[i] = tree[index - 1];
			tree[index--].~Enemy();
		}
		i++;
	}
}


int main(void)
{
	Map					m(HEIGHT, WIDTH);
	ProjectileManager	pm;
	Player				p1;
	Projectile 			proj = Laser();

	p1.setProjectile(proj);
	p1.setAttackSpeed(90);
	p1.setXY(m.lmax / 2, m.cmax - 3);

	int tou = 0;
	init_arena(m);

	CLOCK::time_point lastClock = CLOCK::now();

	while (p1.getHP() != 0)
	{
		CLOCK::time_point now = CLOCK::now();

		tou = ft_mov(m, &p1);

		pm.shoot(&p1, p1.getX(), p1.getY(), -1, 'p');

		ft_score(p1);
		if ((now - lastClock).count() > GAME_CLOCK_TIME)
		{
			lastClock = now;
			
			p1.clock();
			move(p1.getY(), p1.getX());
			addch(p1.getSymbol());

			Enemygen(DIFF, &p1, pm);
			
			ft_tree();
		}
	}
	wclear(stdscr);
	printw("You lose ! Your score: %d", p1.getScore());
	refresh();
	move(1,1);
	while (1);
	endwin();
	return 0;
}
