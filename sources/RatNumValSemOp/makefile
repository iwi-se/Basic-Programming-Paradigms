# Makefile for RatNumRefSemOp
# Author: Ulrich Eisenecker,  March 20, 2025

CXX = g++
CXXFLAGS = -std=c++23 
SRCDIR = src
OBJDIR = obj

# Declare "doc" and "clean" as phony
.PHONY: doc clean

# Rule 1: Define target "all" with dependencies "demo" and "check"
all: demo check

# Rule 2: Define target "demo" with dependency "$(OBJDIR)/demo"
demo: $(OBJDIR)/demo

# Rule 3: Define target "check" with dependency "$(OBJDIR)/check"
check: $(OBJDIR)/check

# Rule 4: Link "demo"
$(OBJDIR)/demo: $(OBJDIR)/main.o $(OBJDIR)/rational_number_operators.o \
$(OBJDIR)/rational_number.o $(OBJDIR)/math_helper.o
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/demo $(OBJDIR)/main.o \
	$(OBJDIR)/rational_number_operators.o \
	$(OBJDIR)/rational_number.o $(OBJDIR)/math_helper.o

# Rule 5: Compile main.cpp
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/rational_number.hpp
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/main.o -c $(SRCDIR)/main.cpp

# Rule 6: Compile math_helper.cpp
$(OBJDIR)/math_helper.o: $(SRCDIR)/math_helper.cpp \
$(SRCDIR)/math_helper.hpp
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/math_helper.o \
	-c $(SRCDIR)/math_helper.cpp

# Rule 7: Compile rational_number.cpp
$(OBJDIR)/rational_number.o: $(SRCDIR)/rational_number.cpp \
$(SRCDIR)/rational_number.hpp $(SRCDIR)/math_helper.hpp
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/rational_number.o \
	-c $(SRCDIR)/rational_number.cpp 

# Rule 8: Compile rational_number_operators.cpp
$(OBJDIR)/rational_number_operators.o: \
$(SRCDIR)/rational_number_operators.cpp \
$(SRCDIR)/rational_number_operators.hpp $(SRCDIR)/rational_number.hpp
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/rational_number_operators.o \
	-c $(SRCDIR)/rational_number_operators.cpp 

# Rule 9: Link "check" and execute it
$(OBJDIR)/check: $(OBJDIR)/full_test.o \
$(OBJDIR)/rational_number_operators.o \
$(OBJDIR)/rational_number.o $(OBJDIR)/math_helper.o \
$(OBJDIR)/catch_amalgamated.o
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/check $(OBJDIR)/full_test.o \
	$(OBJDIR)/rational_number_operators.o \
	$(OBJDIR)/rational_number.o $(OBJDIR)/math_helper.o \
	$(OBJDIR)/catch_amalgamated.o
	$(OBJDIR)/check
   
# Rule 10: Compile full_test.cpp
$(OBJDIR)/full_test.o: \
$(SRCDIR)/full_test.cpp \
$(SRCDIR)/math_helper_test.cpp \
$(SRCDIR)/rational_number_test.cpp \
$(SRCDIR)/rational_number_operators_test.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/full_test.o \
	-c $(SRCDIR)/full_test.cpp 

# Rule 11: Compile catch_amalgamated.cpp
$(OBJDIR)/catch_amalgamated.o: \
$(SRCDIR)/catch_amalgamated.hpp $(SRCDIR)/catch_amalgamated.cpp 
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/catch_amalgamated.o \
	-c $(SRCDIR)/catch_amalgamated.cpp 

# Rule 12: Delete all binaries and executable
clean:
	rm -f $(OBJDIR)/*
	rm -rf doc/*

# Rule 13: Generate documentation
doc:
	doxygen
