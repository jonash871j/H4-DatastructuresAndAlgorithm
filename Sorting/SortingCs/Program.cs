
using System.Diagnostics;

class Sorter
{
	private static void Swap(ref int v1, ref int v2)
	{
		int storeV1 = v1;
		v1 = v2;
		v2 = storeV1;
	}

	public void BubbleSort(int[] numbers)
	{
		for (int i = 0; i < numbers.Length - 1; i++)
		{
			for (int j = 0; j < numbers.Length - i - 1; j++)
			{
				if (numbers[j] > numbers[j + 1])
				{
					Swap(ref numbers[j], ref numbers[j + 1]);
				}
			}
		}
	}

	public void SlectionSort(int[] numbers)
	{
		for (int i = 0; i < numbers.Length; i++)
		{
			int lowestValueIndex = i;
			for (int j = i; j < numbers.Length; j++)
			{
				if (numbers[j] < numbers[lowestValueIndex])
				{
					lowestValueIndex = j;
				}
			}
			Swap(ref numbers[lowestValueIndex], ref numbers[i]);
		}
	}

	public void InsertionSort(int[] numbers)
	{
		for (int i = 1; i < numbers.Length - 1; i++)
		{
			int j = i;
			while (j > 1 && numbers[j - 1] > numbers[j])
			{
				Swap(ref numbers[j], ref numbers[j - 1]);
				j = j - 1;
			}
		}
	}

	private static void Merge(int[] numbers, int start, int mid, int end)
	{
		int i, j, k;
		int n1 = mid - start + 1;
		int n2 = end - mid;

		int[] tempLeftNumbers = new int[n1];
		int[] tempRightNumbers = new int[n2];

		for (i = 0; i < n1; i++)
		{
			tempLeftNumbers[i] = numbers[start + i];
		}
		for (j = 0; j < n2; j++)
		{
			tempRightNumbers[j] = numbers[mid + 1 + j];
		}

		i = 0;
		j = 0;
		k = start;
		while (i < n1 && j < n2)
		{
			if (tempLeftNumbers[i] <= tempRightNumbers[j])
			{
				numbers[k] = tempLeftNumbers[i];
				i++;
			}
			else
			{
				numbers[k] = tempRightNumbers[j];
				j++;
			}
			k++;
		}

		while (i < n1)
		{
			numbers[k] = tempLeftNumbers[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			numbers[k] = tempRightNumbers[j];
			j++;
			k++;
		}
	}

	private static void MergeSortInternal(int[] numbers, int start, int end)
	{
		if (start < end)
		{
			int mid = start + (end - start) / 2;
			MergeSortInternal(numbers, start, mid);
			MergeSortInternal(numbers, mid + 1, end);
			Merge(numbers, start, mid, end);
		}
	}

	public void MergeSort(int[] numbers)
	{
		MergeSortInternal(numbers, 0, numbers.Length - 1);
	}


	private static int Partition(int[] numbers, int start, int end)
	{
		int pivot = numbers[end];
		int i = (start - 1);

		for (int j = start; j <= end - 1; j++)
		{

			if (numbers[j] < pivot)
			{
				i++;
				Swap(ref numbers[i], ref numbers[j]);
			}
		}
		Swap(ref numbers[i + 1], ref numbers[end]);
		return (i + 1);
	}

	private static void QuickSortInternal(int[] numbers, int start, int end)
	{
		if (start < end)
		{

			int pi = Partition(numbers, start, end);
			QuickSortInternal(numbers, start, pi - 1);
			QuickSortInternal(numbers, pi + 1, end);
		}
	}

	public void QuickSort(int[] numbers)
	{
		QuickSortInternal(numbers, 0, numbers.Length - 1);
	}

}

class Program
{
	static void TestSortingAlgorithm(Action<int[]> sortAlgorithmCallback)
	{
		Stopwatch stopwatch = new Stopwatch();
		Random random = new Random();
		int[] randomNumbers = new int[100000];
		for (int i = 0; i < randomNumbers.Length; i++)
		{
			randomNumbers[i] = random.Next(0, 100);
		}

		stopwatch.Restart();
		sortAlgorithmCallback(randomNumbers);
		stopwatch.Stop();
		Console.WriteLine($"\n{sortAlgorithmCallback.Method.Name} finished sorting in {stopwatch.Elapsed.TotalSeconds} seconds with {randomNumbers.Length} random numbers.");

		stopwatch.Restart();
		sortAlgorithmCallback(randomNumbers);
		stopwatch.Stop();
		Console.WriteLine($"Already sorted {sortAlgorithmCallback.Method.Name} finished sorting in {stopwatch.Elapsed.TotalSeconds} seconds with {randomNumbers.Length} random numbers.");
	}

	static void Main()
	{
		Sorter sorter = new Sorter();
		TestSortingAlgorithm(sorter.BubbleSort);
		TestSortingAlgorithm(sorter.SlectionSort);
		TestSortingAlgorithm(sorter.InsertionSort);
		TestSortingAlgorithm(sorter.MergeSort);
		TestSortingAlgorithm(sorter.QuickSort);
	}
}