#### 什么是servlet

https://www.jianshu.com/p/eddbf38618b4



因为web服务器(tomcat、Weblogic、iis、apache)**没有处理动态资源请求的能力**(即该请求需要计算),只能处理静态资源的请求(如果浏览器请求某个html页面，web服务器查看请求的html页面是否存在，存在则返回。)如果要让web服务器处理动态资源的请求，则需要使用CGI[1](https://links.jianshu.com/go?to=https%3A%2F%2Fwww.cnblogs.com%2Fstrive-for-life%2Fp%2F11187253.html%23fn1)程序、组件加容器的方式。

Servlet和Servlet容器使得web服务器有了处理动态资源的能力，Servlet就是web服务器处理动态资源的具体实现。