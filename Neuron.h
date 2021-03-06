#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <iostream>
#include <cmath>
// #include <array>


class Neuron
{
	private :
	
	static constexpr double C_ = 1.0;
	static constexpr double tau_ = 20.0; // neuron time constant
	static constexpr int refractory_period = 20; // in steps
	static constexpr double treshold_potential = 20.0;
	int neuron_steps = 0; // local time of the neuron
	
	double membrane_pot;
	unsigned int num_spikes; // only positive values
	std::vector<int> time_spikes;
	
	static constexpr int delay_steps = 15; // delays time between the time a spike is sent
										   // and the time it is received
										   
	std::vector<int> buffer; // buffer of received spikes
	
	public :
	
	Neuron(double pot, unsigned int spikes); // constructor
	Neuron(); // default constructor
	// Neuron(const Neuron& neuron); // copy constructor
	~Neuron(); // destructor
	
	double getPot() const; //
	unsigned int getNum() const; // getters, const because it doesn't affect the neuron
	double getTimeSpikes(unsigned int spike_number) const; //
	
	/*
	void setPot(double pot); //				
	void setNum(unsigned int spikes); // setters
	void setTimeSpikes(std::vector<double> time); //
	*/
	
	bool isRefractory(int steps); // returns true if the neuron is in a refractory state
	bool hasJustSpiked(int steps);
	
	void update(double dt, double courant);
	
	void storeSpike(int steps);
	
	void sendSpike(Neuron& neuron);
	
};

#endif
