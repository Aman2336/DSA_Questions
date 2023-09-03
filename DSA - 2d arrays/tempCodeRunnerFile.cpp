
        int s = 0;
        int e = (row*col) - 1;
        int mid= s + (e-s)/2;
        while(s<e)
        {
            int e = matrix[mid/col][mid%col];
            if(e == target)
            {
                return 1;
            }
             if(e > target)
            {
                e = mid -1;;
            }
            if(e < target)
            {       
                s= mid+1;
            }
            mid = s+(e-s)/2;
        }
        return 0;