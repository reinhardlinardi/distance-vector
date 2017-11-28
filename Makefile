distance_vector: bin/obj/distance_vector.o
	@echo "Linking ..."
	@g++ bin/obj/distance_vector.o -o distance_vector -g

bin/obj/distance_vector.o: src/distance_vector.cpp
	@echo "Compiling distance_vector.cpp ..."
	@g++ -c src/distance_vector.cpp -o bin/obj/distance_vector.o -g

.PHONY: clean

clean:
	@echo "Removing object files ..."
	@rm -rf bin/obj
	@mkdir bin/obj

	@echo "Removing executable ..."
	@rm -rf distance_vector