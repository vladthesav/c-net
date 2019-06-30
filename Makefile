perceptron: perceptron.c
	gcc -Wall -o perceptron perceptron.c -lm -fsanitize=address
matrix: matrix.c
	gcc -Wall -o matrix matrix.c -lm -fsanitize=address
datagen: datagen.c
	gcc -Wall -o datagen datagen.c -lm -fsanitize=address
