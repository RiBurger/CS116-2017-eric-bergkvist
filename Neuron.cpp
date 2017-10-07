#include "Neuron.h"
#include <cmath>


Neuron::Neuron(double pot, unsigned int spikes, std::vector<double> time)
	: membrane_pot(pot), num_spikes(spikes), time_spikes(time)
	{}
	
Neuron::Neuron()
	: membrane_pot(0.0), num_spikes(0), time_spikes()
	{
		time_spikes.push_back(0.0);
		// std::cout << "Neurone créé" << std::endl;
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

void Neuron::setTimeSpikes(std::vector<double> time)
{
	time_spikes = time;
}

bool Neuron::isRefractory(double time)
{
	if(time_spikes.back() > time - refractory_period)
	{
		std::cout << "refract'" << std::endl;
		return true;
	}
	return false;
}

void Neuron::update(double dt, double courant, double time)
{
	if(isRefractory(time)) // boucle if marche comme il faut
	{
		membrane_pot = 0;
	}
	else 
	{
		if(membrane_pot > treshold_potential)
		{
			std::cout << "Seuil atteint" << std::endl;
			time_spikes.push_back(time);
			std::cout << "Time : " << time << std::endl;
			num_spikes += 1;
			std::cout << "Time_spikes.back() = " << time_spikes.back() << std::endl;
		}
	membrane_pot = exp(-dt/tau_) * membrane_pot + courant * (tau_ / C_) * (1 - exp(-dt/tau_));
	}
}

/*
The way I coded the "update" function implies that when the treshold
is reached, the simtime is memorized, but the membrane potential is
calculated one more time before the next iteration where the 
"isRefractory" function takes back the potential to zero
(membrane_pot should maybe equal zero right away when the treshold
	is reached)
*/
