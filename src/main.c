/*
 *	Copyright (c) 2024, Signaloid.
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */

#include <stdio.h>
#include <math.h>

#include <uxhw.h>

int
main(int argc, char *  argv[])
{
	const double	nominalResistance	= 1000;	/* Nominal value, in Ohms  */
	const double	tolerance		= 0.05;	/* Gold band tolerance, 5% */
	const double	nominalVoltage		= 3.3;	/* Nominal value, in Volts */
	const double	voltageSigma		= 0.01;	/* Standard deviation of voltage */

	double	R;	/* Resistance (Ohms) */
	double	V;	/* Voltage (Volts)   */
	double	P;	/* Power (Watts)     */

	/*
	 *	Set the resistance as a uniform distribution around the nominal value, based on the tolerance.
	 */
	R = UxHwDoubleUniformDist(nominalResistance*(1 - tolerance), nominalResistance*(1 + tolerance));
	printf("R = %lf Ohm\n", R);

	/*
	 *	Set the circuit voltage as a Gaussian distribution around the nominal voltage.
	 */
	V = UxHwDoubleGaussDist(nominalVoltage, voltageSigma);
	printf("V = %lf V\n", V);

	/*
	 *	The power dissipation equation, P = V^2 / R (Equation 1 in README.md).
	 */
	P = pow(V, 2) / R;
	printf("P = %lf W\n", P);

	return 0;
}
