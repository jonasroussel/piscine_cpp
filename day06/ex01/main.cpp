/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:28:15 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 15:23:56 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ctime>
#include <iostream>

struct  Data
{
    std::string s1;
    int         n;
    std::string s2;
};

std::string randomString( size_t size )
{
    const char chars[] = { "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

    std::string str(size, '\0');

    for (size_t i = 0; i < size; i++)
        str[i] = chars[rand() % sizeof(chars)];

    return str;
}

void * serialize( void )
{
    char * raw = new char[sizeof(char *) + sizeof(int) + sizeof(char *)];

    std::string s1 = randomString(8);
    int n = rand() % INT32_MAX;
    std::string s2 = randomString(8);

    std::cout << s1 << " ";
    std::cout << n << " ";
    std::cout << s2 << std::endl;

    int i = 0;

    for (int j = 0; j < 8; j++, i++)
        raw[i] = s1[j];

    for (int j = 0; j < 4; j++, i++)
        raw[19 - i] = (n >> (8 * j)) & 0xff;

    for (int j = 0; j < 8; j++, i++)
        raw[i] = s2[j];

    return raw;
}

Data * deserialize( void * raw )
{
    Data * data = new Data;

    char * bytes = static_cast<char *>(raw);

    for (int i = 0; i < 8; i++)
        data->s1 += bytes[i];
    data->s1[8] = '\0';

    data->n = 0;
    for (int i = 3, j = 0; i >= 0; --i, j++)
        data->n += static_cast<int>((bytes[8 + i] & 0xFF) << (8 * j));

    for (int i = 0; i < 8; i++)
        data->s2 += bytes[12 + i];
    data->s2[8] = '\0';

    return data;
}

int main( void )
{
    srand(time(NULL));

    void * raw = serialize();
    Data * data = deserialize(raw);

    std::cout << data->s1 << " ";
    std::cout << data->n << " ";
    std::cout << data->s2 << std::endl;

    return 0;
}
