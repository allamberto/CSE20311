CMP = g++
MAIN = life
CLASS = lifeboard
EXEC = runit

$(EXEC): $(MAIN).o $(CLASS).o
        $(CMP) $(MAIN).o $(CLASS).o -o $(EXEC)

$(MAIN).o: $(CLASS).h $(MAIN).cpp
        $(CMP) -c $(MAIN).cpp -std=c++11

$(CLASS).o: $(CLASS).h $(CLASS).cpp
        $(CMP) -c $(CLASS).cpp -std=c++11

clean:
        rm *.o
        rm $(EXEC)
