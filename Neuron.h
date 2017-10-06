#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <iostream>
#include <cmath>


class Neuron
{
	private :
	
	static constexpr double C_ = 1.0;
	static constexpr double tau_ = 0.02;
	static constexpr double refractory_period = 0.002;
	static constexpr int treshold_potential = 20;
	
	double membrane_pot;
	unsigned int num_spikes; // only positive values
	std::vector<unsigned int> time_spikes;
	
	public :
	
	Neuron(double pot, unsigned int spikes, std::vector<unsigned int> time); // constructor
	Neuron(); // default constructor
	// Neuron(const Neuron& neuron); // copy constructor
	~Neuron(); // destructor
	
	double getPot() const; //
	unsigned int getNum() const; // getters
	double getTimeSpikes(unsigned int spike_number) const; //
	
	void setPot(double pot); //				
	void setNum(unsigned int spikes); // setters
	void setTimeSpikes(std::vector<unsigned int> time); //
	
	bool isRefractory(double time); // returns true if the neuron is in a refractory state
	
	void update(double dt, double courant, double time);
	
};

#endif
