local

```cpp
#define LOCAL
signed main(){
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    #endif
    clock_t start_time=clock();
    //***************************
    
    //**************************
    clock_t end_time=clock();
    #ifdef LOCAL
    cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
    freopen("CON","r",stdin);
    system("pause");
    #endif
    return 0;
}
```

