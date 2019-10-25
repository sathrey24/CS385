/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Sanjay Athrey  
 * Date        : 9/8/2019
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit) : is_prime_{new bool[limit + 1]}, limit_{limit} {
        sieve();
    }

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    inline int num_primes() const {
        return num_primes_;
    }

    void display_primes() const {
        // TODO: write code to display the primes in the format specified in the
        // requirements document.
        cout << endl;
        cout << "Number of primes found: " << num_primes() << endl;
        cout << "Primes up to " << limit_ << ":" << endl;
        const int max_prime_width = num_digits(max_prime_), primes_per_row = 80 / (max_prime_width + 1);
        // if number of primes is greater than amount per row - wrap around
        if (num_primes_ > primes_per_row){
            int count = 0;
            for(int i = 2; i <= limit_; i++){
                if (count == primes_per_row){           
                    cout << endl; 
                    count = 0;
                }
                else {
                    if (count < primes_per_row){
                        if (is_prime_[i] == true && i < max_prime_){
                            cout << setw(max_prime_width) << i;
                            count++;
                            if(count != primes_per_row) {
                                cout << " ";
                            }
                    }
                    else{
                        if (is_prime_[i] == true){
                        cout << setw(max_prime_width) << i ;
                        count ++;                           
                        }                       
                    }
                }
            }       
        }
     }
     // else amount of primes is less than amount per row  
        else{
            if (num_primes_ <= primes_per_row){
                for (int i = 0; i <= limit_; i++){
                    if (is_prime_[i] == true && i != max_prime_){
                        cout << i << " ";                     
                    }
                    else{
                        if (is_prime_[i] == true){
                            cout << i ;                           
                        }
                    }
                }

            }
        }
    }

private:
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    int count_num_primes() const {
        // TODO: write code to count the number of primes found
        int count = 0;
        for (int i = 0; i <= limit_; i++){
            if (is_prime_[i] == true){
                count ++;
            }     
        }
        return count;
    }

    int num_digits(int num) const {
        // TODO: write code to determine how many digits are in an integer
        // Hint: No strings are needed. Keep dividing by 10.
        int count = 0;
        while (num != 0){
            num = num / 10;
            count++;
            }
        return count;
    }
    

    void sieve() {
        // TODO: write sieve algorithm
        for (int i = 2; i <= limit_; i++){
            is_prime_[i] = true;
        }
        for (int i = 2; i <= sqrt(limit_); i++){
            if (is_prime_[i] == true){
                for ( int j = i * i; j <= limit_; j = j+i){
                    is_prime_[j] = false;
                }
            }

        }
        num_primes_ = count_num_primes();
		// finds max_prime by looping down from limit
		for(int i = limit_; i >= 2; i--){
			if(is_prime_[i]){
				max_prime_ = i;
				break;
			}
		}
    }
};

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    
    PrimesSieve p(limit);
	p.display_primes();

    return 0;
}
