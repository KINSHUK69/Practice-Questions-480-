class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    set<int>a(arr,arr+n);
	    int l=INT_MIN,sl=INT_MIN;
	    n=a.size();
	    if(n<2) return -1;
	    for(auto it:a){
	        if(it>l){
	            sl=l;
	            l=it;
	        }
	        if(it>sl && it!=l){
	            sl=it;
	        }
	    }
	    if(l==sl) return -1;
	    return sl;
	    
	}
};
