// Geometry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "geometry.h"

int main() {
    std::cout << "--- Testing Segment Intersection ---" << std::endl;

    
    Segment<int> s1({ 1, 1 }, { 5, 5 });
    Segment<int> s2({ 1, 5 }, { 5, 1 });
    std::cout << "General intersection (should be 1): " << do_intersect(s1, s2) << std::endl;

    
    Segment<int> s3({ 10, 10 }, { 15, 15 });
    std::cout << "No intersection (should be 0): " << do_intersect(s1, s3) << std::endl;

    
    Segment<int> s4({ 2, 2 }, { 3, 3 });
    std::cout << "Collinear overlap (should be 1): " << do_intersect(s1, s4) << std::endl;

   
    Segment<int> s5({ 5, 5 }, { 7, 7 });
    std::cout << "Collinear touch (should be 1): " << do_intersect(s1, s5) << std::endl;

  
    Segment<int> s6({ 6, 6 }, { 8, 8 });
    std::cout << "Collinear no overlap (should be 0): " << do_intersect(s1, s6) << std::endl;

    
    Segment<int> s7({ 3, 3 }, { 7, 3 });
    std::cout << "T-shape intersection (should be 1): " << do_intersect(s1, s7) << std::endl;

    return 0;
}