for /l %%x in (0, 1, 2) do (
   start tsp.exe ./test/test%%x.i test%%x.o
   FC test%%x.o gans/gtest%%x.o
)