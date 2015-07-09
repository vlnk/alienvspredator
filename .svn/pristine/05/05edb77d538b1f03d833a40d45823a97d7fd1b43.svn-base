/**
 * Declaration of a Random Number Generator
 * @file MersenneTwister.h
 * @author Valentin Laurent
 * @date 11/01/2014
 */
#ifndef MERSENNETWISTER_H
#define MERSENNETWISTER_H

#define N 624						/*!< Period parameters*/
#define M 397						/*!< Period parameters*/
#define MATRIX_A 0x9908b0dfUL		/*!< constant vector a*/
#define UPPER_MASK 0x80000000UL		/*!< most significant w-r bits*/
#define LOWER_MASK 0x7fffffffUL		/*!< least significant r bits*/

/**
 * The Mersenne Twister random number generator.
 * @class MersenneTwister
 * @author Valentin Laurent
 */

class MersenneTwister {
    
private:
    unsigned long m_Mt[N];	/*!< the array for the state vector*/
    int m_nMti;				/*!< m_nMti==N+1 means mt[N] is not initialized*/
    
    void init_by_array(unsigned long init_key[], int key_length);
public:
    MersenneTwister();
    MersenneTwister(unsigned long s);
    MersenneTwister(unsigned long init_key[], int key_length);
    ~MersenneTwister();
    
	void init_genrand(unsigned long s);
    unsigned long genrand_int32(void);
    long genrand_int31(void);
    double genrand_real1(void);
    double genrand_real2(void);
    double genrand_real3(void);
    double genrand_res53(void);
};

#endif /* MERSENNETWISTER_H_ */
