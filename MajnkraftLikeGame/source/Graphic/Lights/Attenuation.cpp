/* 
 * File:   Attenuation.cpp
 * Author: Lukas
 * 
 * Created on Streda, 2015, júl 1, 21:30
 */

#include "Attenuation.h"

Attenuation::Attenuation(float constant, float exponent, float linear) :
constant(constant), exponent(exponent), linear(linear) {
}

float Attenuation::GetConstant() const {
    return constant;
}

float Attenuation::GetExponent() const {
    return exponent;
}

float Attenuation::GetLinear() const {
    return linear;
}

void Attenuation::SetConstant(float constant) {
    this->constant = constant;
}

void Attenuation::SetLinear(float linear) {
    this->linear = linear;
}

void Attenuation::SetExponent(float exponent) {
    this->exponent = exponent;
}

Attenuation::~Attenuation() {
}

