void Insertsort(int *array, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = array[i];//key����ǰ��Ԫ�رȽϵ�Ԫ��
		int end = i - 1;//�����е����һ��Ԫ��
		while (key < array[end] && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
