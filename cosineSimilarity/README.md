# Cosine Similarity Algorithm

This folder contains an implementation of the Cosine Similarity algorithm, a technique widely used in text analysis, information retrieval, and recommendation systems.

## Problem Statement

Given two text documents, determine their similarity based on the frequency of words they contain. Cosine similarity measures the cosine of the angle between two vectors, where each vector represents the word frequencies in a document.

## Implementation Details

- **File**: `cosineSimilarity.cpp`
- **Approach**: Vector space model with term frequency
- **Data Structures**:
  - Unordered set for tracking unique words
  - Vectors for storing words and frequency counts

## Files Included

- **cosineSimilarity.cpp**: Main implementation of the algorithm
- **file1.txt**: Sample text document for comparison
- **file2.txt**: Another sample text document for comparison
- The program will generate two additional files:
  - **merged.txt**: Contains all words from both input files
  - **unique.txt**: Contains only the unique words across both documents

## Algorithm Steps

1. Parse two input text files and extract all words
2. Create a combined set of unique words across both documents
3. For each document, create a vector where each element represents the frequency of a unique word
4. Calculate the cosine similarity between these two vectors:
   - Compute the dot product of the vectors
   - Calculate the magnitudes (L2 norms) of each vector
   - Divide the dot product by the product of the magnitudes

## Mathematical Formula

The cosine similarity between two documents A and B is calculated as:

cos(θ) = (A·B) / (||A|| × ||B||)

Where:
- A·B is the dot product of vectors A and B
- ||A|| and ||B|| are the L2 norms (Euclidean lengths) of vectors A and B

## Time Complexity

- **Word Extraction**: O(n) where n is the total number of words in both documents
- **Unique Word Collection**: O(n) using an unordered_set
- **Frequency Calculation**: O(u × n) where u is the number of unique words
- **Similarity Calculation**: O(u) for vector operations
- **Overall**: O(u × n)

## Space Complexity

- O(n) for storing all words from both documents
- O(u) for storing unique words and frequency vectors

## Applications

Cosine similarity is used in various applications including:
- Document similarity measurement
- Plagiarism detection
- Search engine relevance ranking
- Recommendation systems
- Clustering similar documents

## Usage

### Compilation
```bash
g++ -o cosine_similarity cosineSimilarity.cpp -std=c++11
```

### Execution
```bash
./cosine_similarity
```

The program will:
1. Read the included sample text files (`file1.txt` and `file2.txt`)
2. Extract and merge words from both files
3. Create a list of unique words
4. Generate frequency vectors for each document
5. Calculate and display the cosine similarity as both a value and percentage

### Customization
To use your own text files, either:
- Replace the content of the provided sample files, or
- Modify the file paths in the main function of cosineSimilarity.cpp

## Example Output

When comparing the provided sample files, you should see output similar to:

```
Merged words saved to 'merged.txt'
Unique words saved to 'unique.txt'
Total words in file1: [number]
Total words in file2: [number]
Total unique words: [number]
...
Cosine similarity: [value]
[percentage]% Similarity
``` 