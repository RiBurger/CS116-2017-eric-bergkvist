#include "Neuron.cpp"
#include <cmath>
#include <iostream>
#include <fstream>


int main()
{
	
	std::vector<Neuron> neurons;
	Neuron neuron;
	neurons.push_back(neuron);
	
	double h(0.2); // time interval between two updates (in ms)
	int a; // simulation steps after which the current is active
	int b; // simulation steps after which the current is inactive again
	int n(200); // final number of steps
	int n_steps(0);
	double I_ext(0.0);
	
	// infinite loop if I write a letter instead of a number in the next cout
	
	std::cout << "What's the intensity of the external current?" << std::endl;
	while (I_ext <= 0.0)
	{
		std::cin >> I_ext;
		if (I_ext <= 0)
		{
			std::cout << "The external current intensity must be positive." << std::endl;
			std::cin.clear();
		}
	}
	
	std::cout << "After how many steps of simulation do you want the current to be active?" << std::endl;
	while ((a <= 0) or (a > n))
	{
		std::cin >> a;
		if (a <= 0)
		{
			std::cout << "The value must be positive, and smaller than the total number of steps : " << n << std::endl;
			std::cin.clear();
		}
	}
	
	std::cout << "After how many steps of simulation do you want the current to be inactive again?" << std::endl;
	while ((b < a) or (b > n))
	{
		std::cin >> b;
		if ((b < a) or (b > n))
		{
			std::cout << "The value must be equal or bigger than " << a << ", and smaller than the total number of steps : " << n << std::endl;
			std::cin.clear();
		}
	}
	
	std::ofstream neuron_potential;
	neuron_potential.open("Potential.txt");
	
	double I(0.0);
	
	while (n_steps < n)
	{
		if((n_steps < a) or (n_steps > b))
		{
			I = 0.0;
		}
		else
		{
			I = I_ext;
		}
		
		for (unsigned int i(0); i < neurons.size(); ++i)
		{
			neurons[i].update(h, I, n_steps * h);
			neuron_potential << neurons[i].getPot() << " pA at t = " << n_steps * h << " ms" << std::endl;
			n_steps += 1;
			std::cout << "Membrane_pot : " << neurons[i].getPot() << std::endl;
		}
	}
	
	neuron_potential.close();
	return 0;
}
