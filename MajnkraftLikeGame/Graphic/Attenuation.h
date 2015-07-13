/* 
 * File:   Attenuation.h
 * Author: Lukas
 *
 * Created on Streda, 2015, júl 1, 21:30
 */

#ifndef ATTENUATION_H
#define	ATTENUATION_H

class Attenuation {
public:
    Attenuation(float constant, float exponent, float linear);
 
    float GetConstant() const;
    void SetConstant(float constant);
    float GetExponent() const;
    void SetExponent(float exponent);
    float GetLinear() const;
    void SetLinear(float linear);

    virtual ~Attenuation();
private:
    float constant;
    float linear;
    float exponent;
};

#endif	/* ATTENUATION_H */

