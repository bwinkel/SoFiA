#ifndef PARAMETRIZATION_H
#define PARAMETRIZATION_H

#define PARAMETRIZATION_DEFAULT_SPATIAL_RADIUS  50L
#define PARAMETRIZATION_DEFAULT_SPECTRAL_RADIUS 50L

#define BUSYFIT_FREE_PARAM 8

#include <vector>

#include "BFfit.h"
#include "DataCube.h"
#include "Source.h"

class Parametrization
{
public:
	Parametrization();
	
	int parametrize(DataCube<float> *d, DataCube<short> *m, Source *s, bool doBF = true);
	
private:
	int loadData(DataCube<float> *d, DataCube<short> *m, Source *s);
	int measureCentroid();
	int measureLineWidth();
	int measureFlux();
	int fitEllipse();
	int kinematicMajorAxis();
	int createIntegratedSpectrum();
	int fitBusyFunction();
	int writeParameters();
	
	bool doBusyFunction;
	
	DataCube<float> *dataCube;
	DataCube<short> *maskCube;
	Source          *source;
	
	long searchRadiusX;
	long searchRadiusY;
	long searchRadiusZ;
	
	long subRegionX1;
	long subRegionX2;
	long subRegionY1;
	long subRegionY2;
	long subRegionZ1;
	long subRegionZ2;
	
	struct DataPoint
	{
		long x;
		long y;
		long z;
		float value;
	};
	
	std::vector<struct DataPoint> data;
	double noiseSubCube;
	
	std::vector<double> spectrum;
	std::vector<double> noiseSpectrum;
	double noiseSpectrumMax;
	
	double centroidX;
	double centroidY;
	double centroidZ;
	double errCentroidX;
	double errCentroidY;
	double errCentroidZ;
	double lineWidthW20;
	double lineWidthW50;
	double errlineWidthW20;
	double errlineWidthW50;
	double lineWidthWm50;
	double meanFluxWm50;
	double peakFlux;
	double peakFluxSpec;
	double totalFlux;
	double intSNR;
	double ell3sMaj;
	double ell3sMin;
	double ell3sPA;
	double ellMaj;
	double ellMin;
	double ellPA;
	double kinematicPA;
	bool   flagKinematicPA;
	bool   flagWarp;
	
	int    busyFitSuccess;
	double busyFunctionChi2;
	double busyFitParameters[2 * BUSYFIT_FREE_PARAM + 1];
	//double busyFitUncertainties[BUSYFIT_FREE_PARAM];
	double busyFunctionCentroid;
	double busyFunctionW20;
	double busyFunctionW50;
	double busyFunctionFpeak;
	double busyFunctionFint;
};

#endif
