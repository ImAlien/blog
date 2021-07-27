[TOC]

#### IDEA配置

##### 什么是servlet

https://www.jianshu.com/p/eddbf38618b4

因为web服务器(tomcat、Weblogic、iis、apache)**没有处理动态资源请求的能力**(即该请求需要计算),只能处理静态资源的请求(如果浏览器请求某个html页面，web服务器查看请求的html页面是否存在，存在则返回。)如果要让web服务器处理动态资源的请求，则需要使用CGI[1](https://links.jianshu.com/go?to=https%3A%2F%2Fwww.cnblogs.com%2Fstrive-for-life%2Fp%2F11187253.html%23fn1)程序、组件加容器的方式。

Servlet和Servlet容器使得web服务器有了处理动态资源的能力，Servlet就是web服务器处理动态资源的具体实现。

##### 添加servlet包

右击项目，打开module setting， 添加library

![image-20210429095606171](https://i.loli.net/2021/04/29/QY14sxoNP69EiJB.png)

##### web文件夹

在工程下面新建一个web文件夹，里面存放.class文件和web配置

![image-20210429095220389](https://i.loli.net/2021/04/29/enb7TWESIqNFVux.png)

web.xml中配置网页对应的java文件

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app>

	<servlet>
		<servlet-name>HelloServlet</servlet-name>
		<servlet-class>HelloServlet</servlet-class>
	</servlet>

	<servlet-mapping>
		<servlet-name>HelloServlet</servlet-name>
		<url-pattern>/hello</url-pattern>
	</servlet-mapping>

	<servlet>
		<servlet-name>LoginServlet</servlet-name>
		<servlet-class>LoginServlet</servlet-class>
	</servlet>

	<servlet-mapping>
		<servlet-name>LoginServlet</servlet-name>
		<url-pattern>/login</url-pattern>
	</servlet-mapping>
</web-app>
```

classes存放.class文件

##### 更改输出路径

这样就可以不用在命令行编译了，直接recompile就好了

![image-20210429094936509](https://i.loli.net/2021/04/29/LuglV3b7jDo9xza.png)

##### 部署tomcat

**①、进入到 apache-tomcat-7.0.52\conf\Catalina\localhost 目录，新建一个 项目名.xml 文件**

　**②、在 那个新建的 xml 文件中，增加下面配置语句（和上面的是一样的,但是不需要 path 配置，加上也没什么用）**

　**③、在浏览器输入路径：localhost:8080/xml文件名/访问的文件名**

```
<Context docBase=``"D:/WebProject"` reloadable=``"true"` `/>
```

#### Servlet教程

##### request常见方法

```java
//获取参数
request.getParameter("name");
```



##### response方法

```java
//设置返回的格式
response.setContentType("text/html; charset=UTF-8");
// 返回数据
 html = "<div style='color:green'>登录成功</div>";
 PrintWriter pw = response.getWriter();
 pw.println(html);
//跳转
response.sendRedirect("fail.html"); //方法一

response.setStatus(301); //方法二
response.setHeader("Location", "fail.html");
//不使用缓存
response.setDateHeader("Expires",0 );
response.setHeader("Cache-Control","no-cache");
response.setHeader("pragma","no-cache");
```

