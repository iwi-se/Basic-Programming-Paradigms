# Makefile for RatNumRefSem, January 17, 2023, Author: Ulrich Eisenecker
# Version using variables

CXX = g++
CXXFLAGS = -std=c++23 
SRCDIR = src
OBJDIR = obj

# Rule 1: Link executable
$(OBJDIR)/demo: $(OBJDIR)/main.o $(OBJDIR)/rational_number.o \
$(OBJDIR)/math_helper.o
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/demo $(OBJDIR)/main.o \
	$(OBJDIR)/rational_number.o $(OBJDIR)/math_helper.o

# Rule 2: Compile main.cpp
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/rational_number.hpp
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/main.o -c $(SRCDIR)/main.cpp

# Rule 3: Compile math_helper.cpp
$(OBJDIR)/math_helper.o: $(SRCDIR)/math_helper.cpp $(SRCDIR)/math_helper.hpp
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/math_helper.o -c $(SRCDIR)/math_helper.cpp

# Rule 4: Compile rational_number.cpp
$(OBJDIR)/rational_number.o: $(SRCDIR)/rational_number.cpp \
$(SRCDIR)/rational_number.hpp $(SRCDIR)/math_helper.hpp
	$(CXX) $(CXXFLAGS) -o $(OBJDIR)/rational_number.o -c \
	$(SRCDIR)/rational_number.cpp 

# Rule 5: Delete all binaries and executable
clean:
	rm -f $(OBJDIR)/*
	rm -rf doc/*

.PHONY: doc

# Rule 6: Generate documentation
doc:
	doxygen
