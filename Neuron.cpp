#include "Neuron.h"
#include <cmath>


Neuron::Neuron(double pot, unsigned int spikes, std::vector<unsigned int> time)
	: membrane_pot(pot), num_spikes(spikes), time_spikes(time)
	{}
	
Neuron::Neuron()
	: membrane_pot(0.0), num_spikes(0), time_spikes()
	{
		time_spikes.push_back(0);
	}

/*
Neuron::Neuron(const Neuron& neuron)
	: MembranePot(neuron.getMembranePot()), NumberSpikes(neuron.getNumberSpikes()), TimeOfSpikes(neuron.getTimeOfSpikes())
	{}
*/	
	
Neuron::~Neuron() {}

double Neuron::getPot() const
{
	return membrane_pot;
}

unsigned int Neuron::getNum() const
{
	return num_spikes;
}

double Neuron::getTimeSpikes(unsigned int spike_number) const
{
	return time_spikes[(spike_number)-1];
} 

void Neuron::setPot(double pot)
{
	membrane_pot = pot;
}
			
void Neuron::setNum(unsigned int spikes)
{
	num_spikes = spikes;
}

void Neuron::setTimeSpikes(std::vector<unsigned int> time)
{
	time_spikes = time;
}

bool Neuron::isRefractory(double time)
{
	if(time_spikes.back() > time - refractory_period)
	{
		return true;
	}
	return false;
}

void Neuron::update(double dt, double courant, double time)
{
	if(isRefractory(time))
	{
		membrane_pot = 0;
	}
	else if(membrane_pot > treshold_potential)
	{
		time_spikes.push_back(time);
		num_spikes += 1;
	}
	membrane_pot = exp(-dt/tau_) * membrane_pot + courant * (tau_ / C_) * (1 - exp(-dt/tau_));
}

