/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:50:14 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/14 11:37:33 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	// Create an an instance of Data
	Data myData = {"Johnny", 74};

	// Serialize the data
	uintptr_t serializedData = Serializer::serialize(&myData);

	// Deserialize the data
	Data *deserializedData = Serializer::deserialize(serializedData);

	// Prints the original and deserialized data
	std::cout << "Name: " << myData.name << ", Age: " << myData.age << std::endl;
	std::cout << "Name: " << deserializedData->name << ", Age: " << deserializedData->age << std::endl;

	return (0);
}
