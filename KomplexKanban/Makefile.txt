
CXX = clang++

testall: testadd testsub testplusequals testexp testimag testpolar testabs testsqrt testconj testlog testlog10 testnorm testpow testreal testtan testcos testsin testmult testdiv

testadd:	./tests/complex_addition_test.cpp ./lib/complex_addition.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_addition_test.cpp ./tests/catch_amalgamated.o
	-./a.out
	
testsub:	./tests/complex_subtraction_test.cpp ./lib/complex_subtraction.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_subtraction_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testplusequals: ./tests/complex_plusequals_test.cpp ./lib/complex_plusequals.cpp 
	$(CXX) $(CXXFLAGS) ./tests/complex_plusequals_test.cpp ./tests/catch_amalgamated.o
	-./a.out
	

testexp: ./tests/complex_exp_test.cpp ./lib/complex_exp.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_exp_test.cpp  ./tests/catch_amalgamated.o
	-./a.out
	

testimag: ./tests/complex_imag_test.cpp ./lib/complex_imag.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_imag_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testpolar: ./tests/complex_polar_test.cpp ./lib/complex_polar.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_polar_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testabs: ./tests/complex_abs_test.cpp ./lib/complex_abs.cpp 
	$(CXX) $(CXXFLAGS) ./tests/complex_abs_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testsqrt: ./tests/complex_sqrt_test.cpp ./lib/complex_sqrt.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_sqrt_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testconj: ./tests/complex_conj_test.cpp ./lib/complex_conj.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_conj_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testlog: ./tests/complex_log_test.cpp ./lib/complex_log.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_log_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testlog10: ./tests/complex_log10_test.cpp ./lib/complex_log10.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_log10_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testnorm: ./tests/complex_norm_test.cpp ./lib/complex_norm.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_norm_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testpow: ./tests/complex_pow_test.cpp ./lib/complex_pow.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_pow_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testreal: ./tests/complex_real_test.cpp ./lib/complex_real.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_real_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testtan: ./tests/complex_tan_test.cpp ./lib/complex_tan.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_tan_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testcos: ./tests/complex_cos_test.cpp ./lib/complex_cos.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_cos_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testsin: ./tests/complex_sin_test.cpp ./lib/complex_sin.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_tan_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testmult: ./tests/complex_multiplication_test.cpp ./lib/complex_multiplication.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_multiplication_test.cpp ./tests/catch_amalgamated.o
	-./a.out

testdiv: ./tests/complex_division_test.cpp ./lib/complex_division.cpp
	$(CXX) $(CXXFLAGS) ./tests/complex_division_test.cpp ./tests/catch_amalgamated.o
	-./a.out
