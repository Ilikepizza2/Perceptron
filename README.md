# Perceptron Implementation in C++

This C++ program demonstrates a basic implementation of a perceptron trained using the loss function and the perceptron trick. The perceptron is a fundamental building block of neural networks and is capable of binary classification.

## Getting Started

### Prerequisites

- C++ Compiler

### Usage

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/perceptron-cpp.git
    ```

2. Compile the C++ program:

    ```bash
    g++ perceptron.cpp -o perceptron
    ```

3. Run the executable:

    ```bash
    ./perceptron
    ```

### Input Data

The program expects two CSV files:

1. `train.csv` - Training data containing input features and corresponding binary labels.
2. `test.csv` - Testing data for evaluating the trained perceptron.

## Code Overview

- `split_nums`: Function to split a string into a vector of doubles.
- `printCols`: Function to print input features and labels.
- `sum`: Function to calculate the sum of two vectors, including a bias term.
- `classifier`: Function to classify input using the trained perceptron.

The program performs training using the perceptron trick and then tests the perceptron on a separate dataset.

## Parameters

- Learning Rate: 0.1
- Epochs: 1000

## Considerations
- This is a very basic single neuron perceptron with random weights. The sample data given is also very small (~100 rows). So the current outputs may vary `a lot`. Thus, it is for learning purposes only.

## Contributing

Feel free to contribute by opening issues or submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- Inspired by the concept of perceptrons and neural networks.
