# Summary of Michael Nielsen’s Neural Networks and Deep Learning book chapter 1 
This book is about using neural networks to recognize handwritten digits , It covers the basics of neural networks and  deep learning

## **Perceptrons**

### **Concepts:**
- Basic artificial neurons that produce binary outputs based on weighted inputs and a threshold.
- The output is determined by a step function: output = 0 if the weighted sum (Σ(wj xj)) is less than or equal to a threshold, and output = 1 if it exceeds the threshold.
- By adjusting weights and threshold, different decision boundaries can be established.
### **Visualization:**
- Activation Function: The perceptron uses a step function to produce discrete outputs, resulting in a binary decision (0 or 1).
- Output Range: The output is binary, making it suitable for simple classification tasks where data is linearly separable.
- Network Representation: Perceptrons can be organized in layers, where the output of one layer serves as input to the next layer, allowing for complex decision-making through multiple layers.
### **Limitations:**
- Linear Separability: Perceptrons are limited to classifying data that is linearly separable. They cannot handle complex patterns that require non-linear decision boundaries.
- Complexity Handling: They struggle with problems like the XOR function
- a small change in the weights or bias of any single perceptron in the network can sometimes cause the output of that perceptron to completely flip, leading to complex changes in the behavior of the rest of the network

### **Exercises Conclusion :**
Multiplying the weights and biases of a perceptron by a positive constant c does not change its behavior because the decision boundary (whether the output is 0 or 1) depends only on the sign of w⋅x+b, which is unchanged by this scaling.

---

## **Sigmoid**
### **Concepts:**
-  Artificial neurons with continuous inputs and outputs, using the sigmoid function to produce outputs.
- The sigmoid function smooths out the binary step function, producing outputs between 0 and 1. The output approaches 1 for large positive inputs and 0 for large negative inputs.
- The smooth nature of the sigmoid function allows for learning through small adjustments in weights and biases.

### **Visualization:**
- Activation Function: The sigmoid function provides a smooth curve for output values, in contrast to the step function of perceptrons.
- Output Range: The output is a continuous value between 0 and 1, useful for representing probabilities or continuous values in various tasks.
- Network Representation: In a network of sigmoid neurons, the output of one neuron can serve as input to other neurons, building complex decision-making layers.

### **Limitations:**
- Linear Separability: While sigmoid neurons offer a smoother transition, they still have limitations similar to perceptrons regarding linear separability.
- Approximation Limits: A sigmoid neuron network can behave like a perceptron network in some cases, but differences occur when the input results in a zero dot product plus the bias.

---

## **Softmax**
### **Concepts:**
-  produce probabilistic outputs for multi-class classification problems.
- The softmax function converts a vector of raw scores into probabilities, where each output is in the range of 0 to 1 and all outputs sum up to 1.
- The softmax function emphasizes the largest values in the input vector and suppresses smaller values, providing a normalized probability distribution over multiple classes.

### **Visualization:**
- Activation Function: The softmax function applies exponentiation to each input value and normalizes by the sum of exponentiated values, producing a probability distribution.
- Output Range: The output for each neuron is a probability between 0 and 1, and the sum of all outputs equals 1, making it suitable for classification tasks where each input belongs to one of several classes.
- Network Representation: In a network, softmax neurons are often used in the final layer to produce class probabilities from logits, enabling classification based on the highest probability.

### **Limitations:**
- Interpretation: The softmax function assumes that each class is mutually exclusive. If classes are not mutually exclusive, or if there are more complex relationships, softmax may not be appropriate.

---

## **Types of Neural Networks**

### **Feedforward Neural Networks:**

- Concept: Output from one layer is used as input to the next layer without feedback loops.
- Characteristics: Information always moves forward, and these networks are simpler due to the lack of cycles.

### **Recurrent Neural Networks (RNNs):**

- Concept: Networks that include feedback loops where neurons can influence each other over time.
- Characteristics: More complex,better at handling problems requiring memory or sequential information. 

---

## **Cost Function:**
- Measures the difference between predicted and actual outputs, and Minimized during training to improve model performance
- It Guides optimization algorithms like gradient descent to adjust model parameters and reduce errors.

### **Types:**
- **Quadratic (MSE):** For regression, averages squared differences between predicted and actual values.
- **Cross-Entropy:** For classification, measures the difference between predicted and actual probability distributions.

---

## **Gradient Descent (GD)**
**Method:**
- Batch Processing: Computes the gradient of the cost function using the entire training dataset.
- Update: Updates the weights and biases after processing the whole dataset.

**Advantages:**
- Provides a more accurate estimate of the gradient since it's based on the full dataset.

**Disadvantages:**
- Can be very slow and memory-intensive, especially with large datasets, because it requires processing the entire dataset for each update.
- May get stuck in local minimum and requires careful tuning of the learning rate.

## **Stochastic Gradient Descent (SGD)**
**Method:**
- Incremental Processing: Computes the gradient of the cost function using a randomly chosen subset of the training data (mini-batch).
- Update: Updates the weights and biases after each mini-batch.
  
**Advantages:**
- Much faster and more efficient, especially with large datasets, because it updates weights more frequently.
- Escaping Local Minimum
  
**Disadvantages:**
- The gradient estimates can be noisy due to the small size of mini-batches, leading to fluctuating cost values.

