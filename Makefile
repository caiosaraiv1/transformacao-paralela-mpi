CC = mpicc
CFLAGS = -Iinclude
TARGET = media_mpi
SRC = src/main.c src/transform.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	mpirun -np 5 ./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
