#ifndef EKF_H
#define EKF_H

#include "Eigen/Cholesky"
#include "Eigen/Core" 
#include "Eigen/LU"
#include "CSMmap.h"
#include <vector>


namespace amcl{
	//typedef Eigen::MatrixXd GaussianCell; 
    double normpdf(double dist, double mu, double sigma);

class EKF{
public:

EKF(Eigen::Vector3d& initPose, Eigen::Matrix3d& initCov, Eigen::MatrixXd& Gaussian_map, double res, float origin_x, float origin_y);
virtual ~EKF();
void run(Eigen::Vector3d& Pre_odom, Eigen::Vector3d& Cur_odom, double* laserRange, double* theta, int range_count, double maxRange);
void SearchBestAlign(Eigen::Vector3d* Pose, double* laserRange, double* theta, int range_count, float xRange, float yRange, float del_Range, float ThRange, float del_Th, bool cal_cov, Eigen::Matrix3d* cov, double maxRange);	

Eigen::Vector3d initPose_;
Eigen::Vector3d latestPose_;	
Eigen::Matrix3d initconv_;
Eigen::Matrix3d latestconv_;
Eigen::MatrixXd GaussianMap_;
double resolution_;
int rows_;
int cols_;
float originalx_;
float originaly_;
private:
/*
	Eigen::Vector3d initPose_;
	Eigen::Vector3d latestPose_;
	double res_;
	int width_, height_;
    double origin_x,origin_y;
*/

};

}
#endif
