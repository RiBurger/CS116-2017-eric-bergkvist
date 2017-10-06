#include "Neuron.cpp"
#include <cmath>
#include <iostream>
#include <fstream>


int main()
{
	
	std::vector<Neuron> neurons;
	Neuron neuron;
	neurons.push_back(neuron);
	
	double t = 0;
	double h(0.0002); // time interval between two updates
	int a; // simulation steps after which the current is active
	int b; // simulation steps after which the current is inactive again
	int n(1000); // number of steps
	double t_final = n * h; 
	double I_ext(0.0);
	
	
	
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
	
	while (t < t_final)
	{
		for (auto neuron : neurons)
		neuron.update(h, I_ext, t);
		neuron_potential << neuron.getPot() << std::endl;
		t += h;
	}
	return 0;
}
