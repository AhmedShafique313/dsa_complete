import matplotlib.pyplot as plt
import pandas as pd

def plot_timing_data(filename):
    data = pd.read_csv(filename, header=None, names=['Algorithm', 'Size', 'Time'])

    # Plot
    plt.figure(figsize=(10, 6))
    for algorithm in data['Algorithm'].unique():
        algorithm_data = data[data['Algorithm'] == algorithm]
        plt.plot(algorithm_data['Size'], algorithm_data['Time'], label=algorithm)

    plt.xlabel('Size of Input (log scale)')
    plt.ylabel('Time (milliseconds)')
    plt.title('Sorting Algorithm Performance')
    plt.legend()
    plt.grid(True)
    plt.yscale('log')  # Logarithmic scale on the y-axis
    plt.xscale('log')  # Logarithmic scale on the x-axis
    plt.show()

if __name__ == '__main__':
    plot_timing_data('timing_data.csv')
