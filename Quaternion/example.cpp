#include <iostream>
#include "Quaternion.h"

int main(int argc, char **argv) {    

    Quaternion<int> a(1,0,1,0);
    Quaternion<double> b(1,0.5,0.5,0.75);
    Quaternion<float> c(3,0.5,1.5,0.75);
        
    std::complex<double> ca(1,2);
    std::complex<double> cb(3,4);
            
    std::cout << "Real part of " << a << " is " << a.real() << std::endl;
    
    std::cout << "Unreal part of " << b << " is " << b.unreal() << std::endl;
    
    std::cout << "Component of " << a << " is " << a.a() << ", " << a.b() << ", " << a.c() << ", " << a.d() << std::endl;
    
    std::cout << "Norm of " << a << " is " << std::norm(a) << std::endl;
        
    std::cout << "Modulus of " << c << " is " << std::abs(c) << std::endl;

    std::cout << "Conjugate of " << b << " is " << std::conj(b) << std::endl;
    
    std::cout << "Normalization of " << b << " is " << normalized(b) << std::endl;
        
    std::cout << "Inverse of " << b << " is " << inverse(b) <<  std::endl;
    
    std::cout << a << " + " << b << " = " << a + b << std::endl;
        
    std::cout << a << " + " << 3 << " = " << a + 3 << std::endl;
        
    std::cout << b << " + complex " << ca << " = " << b + ca << std::endl;
    
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    
    std::cout << a << " * " << b << " = " << a * b << std::endl;

    std::cout << a << " * " << 2.2 << " = " << a * 2.2 << std::endl;
    
    std::cout << a << " / " << b << " = " << a / b << std::endl;

    std::cout << a << " / " << 2.2 << " = " << a / 2.2 << std::endl;
        
    std::cout << 2.2 << " / " << b << " = " << 2.2 / b << std::endl;
    
    Quaternion<double> component (ca,cb);
    
    std::cout << "Construct quaternion from complex " << ca << " and " << cb << " = " << component <<  std::endl;
    
    std::cout << "Quaternion " << component << " has complex component " << component.complex_a() << " and " << component.complex_b() <<  std::endl;

    Quaternion<double> conversion = euler_to_quaternion<double>(-1.14159, 0.141593, 0.858407);
    
    std::cout << "Convert Euler angles [roll = -1.14159, pitch = 0.141593, yaw = 0.858407] to quaternion: " << conversion <<  std::endl;
    
    auto [roll, pitch, yaw] = quaternion_to_euler(conversion);
    
    std::cout << "Convert quaternion " << conversion << " back to Euler angles: [roll = " << roll << ", pitch = "<< pitch <<", yaw = "<< yaw <<"]" <<  std::endl;
    
    std::cout << a << " is NaN? " << std::boolalpha << std::isnan(a) << std::endl;
    
    std::cout << a << " is infinite? " << std::boolalpha << std::isinf(a) << std::endl;

    std::cout << a << " is finite? " << std::boolalpha << std::isfinite(a) << std::endl;

    return 0;
    
}
