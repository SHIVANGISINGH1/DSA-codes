
long long int floorSqrt(long long int num) 
{    
    if (num==0) return 0;    
    
	long long int left = 1;
	long long int right = num;
	
	while (left<=right)
	{
		long long int mid= left + (right - left)/2;

	    if (mid*mid==num)     // check if mid*mid is equal to the num  return mid(square root)
		{
			return mid;
		}
		else if (mid*mid>num)  
		{
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
	   
	}
	return left-1; // return right of left-1 (floor)
}