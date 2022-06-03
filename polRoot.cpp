#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>

double f(double x, std::vector <double> poly);
double derf(double x, std::vector <double> poly);

double Bisection(std::vector <double> poly, double a, double b, double eps, int maxIt, std::string arr[3]);
double Newton(std::vector <double> poly, double x, double eps, double delta, int maxIt, std::string arr[3]);
double Secant(std::vector <double> poly, double a, double b, double eps, int maxIt, std::string arr[3]);
double Hybrid(std::vector <double> poly, double a, double b, double eps, int maxIt, std::string arr[3]);

int main(int argc, char *argv[])
{
    std::string input = "";
    
    if(argc < 4){std::cout << "not enough arguments" << std::endl; return 0;}
    else{input = argv[(argc-1)];}

    std::ifstream MyFile(input);
    if (!MyFile.is_open()) {
        std::cout << "File " << input << " Not Found." << std::endl;
    }
    else {
        input = input.substr(0, input.size() - 4);
        int exp = 0;
        MyFile >> exp;
        std::vector<double> vec(exp+2);
        vec[0] = exp;
        for (int k = 1; k <= vec.size(); k++) { MyFile >> vec[k];}

        std::string arg1 = argv[1];
        std::string arg2 = argv[2];
        std::string arg3 = argv[3];
        int maxIt = 10000;
        std::string sol[3]={"","0",""};
        if(argc == 4){ 
            if(arg1 == "-newt"){
                try{   
                    double x = std::stod(arg2);
                    std::ofstream newFile;
                    newFile.open(input + ".sol");
                    Newton(vec, x, pow(2, -32), .00001 , maxIt, sol);
                    for (int i = 0; i < 3; i++) { newFile << std::setprecision(20) << sol[i] << " "; }
                    newFile.close();
                    MyFile.close();
                    return 0;
                }
                catch(std::exception& e){
                    std::cout << "Failed: Argument must be a valid number" << std::endl;
                }
            }
            else{
                try{
                    double a = std::stod(arg1);
                    double b = std::stod(arg2);

                    std::ofstream newFile;
                    newFile.open(input + ".sol");
                    Bisection(vec, a,b ,pow(2, -32), maxIt, sol);
                    for (int i = 0; i < 3; i++) { newFile << std::setprecision(20) << sol[i] << " "; }
                    newFile.close();

                    MyFile.close();
                    return 0;
                }
                catch(std::exception& e){
                    std::cout << "Failed: Arguments must be valid numbers" << std::endl;
                }
            }
            std::cout<<"Invalid arguments"<<std::endl;
            MyFile.close();
            return 0;
        }
        else if(argc == 5){
            if(arg1 == "-sec"){
                try{
                double a = std::stod(arg2);
                double b = std::stod(arg3);std::ofstream newFile;
                newFile.open(input + ".sol");
                Secant(vec, a, b, pow(2, -32), maxIt, sol);
                for (int i = 0; i < 3; i++) { newFile << std::setprecision(20) << sol[i] << " "; }
                newFile.close();
                MyFile.close();
                return 0;
                }
                catch(std::exception& e){
                    std::cout << "Failed: Arguments must be valid numbers" << std::endl;
                }
            }
            else if(arg1 == "-hybrid"){
                try{
                    double a = std::stod(arg2);
                    double b = std::stod(arg3);
                    std::ofstream newFile;
                    newFile.open(input + ".sol");
                    Hybrid(vec, a,b ,pow(2, -32), maxIt, sol);
                    for (int i = 0; i < 3; i++) { newFile << std::setprecision(20) << sol[i] << " "; }
                    newFile.close();
                    MyFile.close();
                    return 0;
                }
                catch(std::exception& e){
                    std::cout << "Failed: Arguments must be valid numbers" << std::endl;
                }
            }
            std::cout<<"Invalid arguments"<<std::endl;
            MyFile.close();
            return 0;
        }
        else if(argc == 6){
            std::string arg4 = argv[4];
            if(arg1 == "-newt"){
                if(arg2 == "-maxIt" || arg2 == "-maxIter"){
                    try{
                        maxIt = std::stoi(arg3);
                        double x = std::stod(arg4);
                        std::ofstream newFile;
                        newFile.open(input + ".sol");
                        Newton(vec, x, pow(2, -32), .00001 , maxIt, sol);
                        for (int i = 0; i < 3; i++) { newFile << std::setprecision(20) << sol[i] << " "; }
                        newFile.close();
                        MyFile.close();
                        return 0;
                    }
                    catch(std::exception& e){
                        std::cout << "Failed: Arguments must be valid numbers" << std::endl;
                    }
                }
            }
            else{
                if(arg1 == "-maxIt" || arg1 == "-maxIter"){
                    try{
                        maxIt = std::stoi(arg2);
                        double a = std::stod(arg3);
                        double b = std::stod(arg4);
                        std::ofstream newFile;
                        newFile.open(input + ".sol");
                        Bisection(vec, a,b ,pow(2, -32), maxIt, sol);
                        for (int i = 0; i < 3; i++) { newFile << std::setprecision(20) << sol[i] << " "; }
                        newFile.close();
                        MyFile.close();
                        return 0;
                    }
                    catch(std::exception& e){
                        std::cout << "Failed: Arguments must be valid numbers" << std::endl;
                    }
                }
            }
            std::cout<<"Invalid arguments"<<std::endl;
            MyFile.close();
            return 0;
        }
        else if(argc == 7){
            std::string arg4 = argv[4];
            std::string arg5 = argv[5];
            if(arg1 == "-sec"){
                if(arg2 == "-maxIt" || arg2 == "-maxIter"){
                    try{
                    maxIt = std::stoi(arg3);
                        double a = std::stod(arg4);
                        double b = std::stod(arg5);
                        std::ofstream newFile;
                        newFile.open(input + ".sol");
                        Secant(vec, a, b, pow(2, -32), maxIt, sol);
                        for (int i = 0; i < 3; i++) { newFile << std::setprecision(20) << sol[i] << " "; }
                        newFile.close();
                        MyFile.close();
                        return 0;
                    }
                    catch(std::exception& e){
                        std::cout << "Failed: Arguments must be valid numbers" << std::endl;
                    }
                }
            }
            else if(arg1 == "-hybrid"){
                if(arg2 == "-maxIt" || arg2 == "-maxIter"){
                    try{
                        maxIt = std::stoi(arg3);
                        double a = std::stod(arg4);
                        double b = std::stod(arg5);
                        std::ofstream newFile;
                        newFile.open(input + ".sol");
                        Hybrid(vec, a,b ,pow(2, -32), maxIt, sol);
                        for (int i = 0; i < 3; i++) { newFile << std::setprecision(20) << sol[i] << " "; }
                        newFile.close();
                        MyFile.close();
                        return 0;
                    }
                    catch(std::exception& e){
                        std::cout << "Failed: Arguments must be valid numbers" << std::endl;
                    }   
                }
            }
            std::cout<<"Invalid arguments"<<std::endl;
            MyFile.close();
            return 0;
        }
        else std::cout<<"Invalid arguments"<<std::endl;
    }
    MyFile.close();
}

double Bisection(std::vector <double> poly, double a, double b, double eps, int maxIt, std::string arr[3]) {
    double fa = f(a, poly);
    double fb = f(b, poly);
    double c = -1.0;
    if (fa * fb >= 0) { std::cout << "Inadequate values for a and b." << std::endl; return -1.0; }
    
    double error = b - a;

    for (int it = 0; it < maxIt; it++) {
        error = error / 2;
        c = a + error;
        double fc = f(c, poly);

        if ( abs(error) < eps || fc == 0) {
            std::stringstream result;
            result.precision(30);
            result<<c;
            arr[0]=result.str();
            arr[1]=std::to_string(it+1);
            arr[2]="Converged";
            return c;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
    }
    //std::cout << "Max iterations reached without convergence..." << std::endl;
    std::stringstream result;
    result.precision(30);
    result<<c;
    arr[0]=result.str();
    arr[1]=std::to_string(maxIt);
    arr[2]="Did Not Converge";
    return c;
}

double Newton(std::vector <double> poly, double x, double eps, double delta, int maxIt, std::string arr[3]) {
    double fx = f(x, poly);

    for (int it = 0; it < maxIt; it++) {
        double fd = derf(x, poly);
        
        if (abs(fd) < delta) {
            std::cout << "Small slope!" << std::endl;
            std::stringstream result;
            result.precision(30);
            result<<x;
            arr[0]=result.str();
            //std::string temp = arr[1];
            arr[1]=std::to_string(stoi(arr[1]) + it+1);
            arr[2]="Converged";
            return x;
        }

        double d = fx / fd;
        x = x - d;
        fx = f(x, poly);

        if (abs(d) < eps) {
            //std::cout << "Algorith converged after #" << it+1 << " iterations!" << std::endl;
            std::stringstream result;
            result.precision(30);
            result<<x;
            arr[0]=result.str();
            //std::string temp = arr[1];
            arr[1]=std::to_string(stoi(arr[1]) + it+1);
            arr[2]="Converged";
            return x;
        }
    }
    std::stringstream result;
    result.precision(30);
    result<<x;
    arr[0]=result.str();
    arr[1]=std::to_string(stoi(arr[1]) + maxIt);
    arr[2]="Did Not Converge";
    return x;
}

double Secant(std::vector <double> poly, double a, double b, double eps, int maxIt, std::string arr[3]) {
    double fa = f(a, poly);
    double fb = f(b, poly);


    for (int it = 0; it < maxIt; it++) {
        double d = (b - a) / (fb - fa);
        b = a;
        fb = fa;
        d = d * fa;
        if (abs(d) < eps) {
            std::stringstream result;
            result.precision(30);
            result<<a;
            arr[0]=result.str();
            arr[1]=std::to_string(it+1);
            arr[2]="Converged";
            return a;
        }

        a = a - d;
        fa = f(a, poly);
    }

    //std::cout << "Maximum number of iterations reached!" << std::endl;
    std::stringstream result;
    result.precision(30);
    result<<a;
    arr[0]=result.str();
    arr[1]=std::to_string(maxIt);
    arr[2]="Did Not Converge";
    return a;
}

double Hybrid(std::vector <double> poly, double a, double b, double eps, int maxIt, std::string arr[3]) {
    
    double biAn = Bisection(poly, a, b, eps, 6, arr);
    if(arr[2] == "Converged") return stod(arr[0]);
    return Newton(poly, biAn, eps, .00001 , maxIt-6, arr);
}

double f(double x, std::vector <double> poly) {
    double ans =0;
    int pos = poly[0];
    for (int i = 1; i <= poly[0]; i++) {
        ans += poly[i] * pow(x, pos);
        pos--;
    }
    return ans + poly[poly.size()-1];
}

double derf(double x, std::vector <double> poly) {
    double ans = 0;
    int pos = poly[0];
    for (int i = 1; i <= poly[0]; i++) {
        ans += poly[i] *  pos * pow(x, pos-1);
        pos--;
    }
    return ans;
}