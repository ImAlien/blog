### PX、DP、SP的区别

**px ： 其实就是像素单位，比如我们通常说的手机分辨列表800\*400都是px的单位**
**sp ： 同dp相似，还会根据用户的字体大小偏好来缩放**
**dp ： 虚拟像素，在不同的像素密度的设备上会自动适配**
**dip： 同dp**

##### 一些概念

dpi全称是dots per inch，对角线每英寸的像素点的个数

dp也叫dip，是device independent pixels。设备不依赖像素的一个单位

##### 参考：

https://blog.csdn.net/donkor_/article/details/77680042

```java
//设置字体大小
textView.setTextSize(TypedValue.COMPLEX_UNIT_SP,45); //设置45SP
```



