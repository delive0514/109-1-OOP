#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Vector {
public:
	Vector(){
		_dim=0;
		_v=new double [_dim];
	}
	Vector(double v[], int dim) {
		if(v != NULL){
		copy(dim,v);
		}
		else{
			_dim=dim;
			_v=new double[dim];
		}
    }

	Vector(Vector const & v){
		copy(v._dim,v._v);
    }

	// destructor
	~Vector() {
		if(_v != NULL){
			delete [] _v;
		}
    }
	// constant member function
	int dim() const{
		return _dim;
    }

	double & at(int i) const{
		return _v[i-1];
    }

	void subtract(Vector const & v){
		if(_dim != v._dim){
			throw string("undefined");
		}
		for(int i=0;i<_dim;i++){
			_v[i]=_v[i]-v._v[i];
		}
    }

	void add(Vector const & v){
		if(_dim != v._dim){
			throw string("undefined");
		}
		for(int i=0;i<_dim;i++){
			_v[i]=_v[i]+v._v[i];
		}
    }

	Vector & operator = (Vector const & u){
		if(_v != NULL){
			delete [] _v;
		}
		copy(u._dim,u._v);
		return *this;
    }

	Vector operator - (Vector const & v) const{
		if(_dim != v._dim){
			throw string("undefined");
		}
		double *temp;
		temp=new double[_dim];
		for(int i=0;i<_dim;i++){
			temp[i]=_v[i]-v._v[i];
		}
		return Vector(temp,_dim);
    }

	Vector operator + (Vector const & v) const{
		if(_dim != v._dim){
			throw string("undefined");
		}
		double *temp;
		temp=new double[_dim];
		for(int i=0;i<_dim;i++){
			temp[i]=_v[i]+v._v[i];
		}
		return Vector(temp,_dim);
    }

	double length() const {
		double s=0;
		for(int i=0;i<_dim;i++){
			s+=_v[i]*_v[i];
		}
		return sqrt(s);
    }

private:
	int _dim;
	double * _v;
	void copy(int dim, double v[]){
		_v= new double [dim];
		_dim=dim;
		for(int i=0;i<dim;i++){
			_v[i]=v[i];
		}
    }
};

#endif
