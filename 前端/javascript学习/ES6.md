### 解构赋值

#### 对象

```js
//用自动解包赋值
const HIGH_TEMPERATURES = {
  yesterday: 75,
  today: 77,
  tomorrow: 80
};
const {today, tomorrow} = HIGH_TEMPERATURES;
//赋值给别的变量
const {today:highToday,tomorrow:highTomorrow }= HIGH_TEMPERATURES;
//嵌套
const LOCAL_FORECAST = {
  yesterday: { low: 61, high: 75 },
  today: { low: 64, high: 77 },
  tomorrow: { low: 68, high: 80 }
};
const {today: { low:lowToday, high:highToday}} = LOCAL_FORECAST;
```

#### 数组

```js
const [a, b,,, c] = [1, 2, 3, 4, 5, 6];
console.log(a, b, c); // 1 2 5
const [a, b, ...arr] = [1, 2, 3, 4, 5, 7];
```

#### 函数

```js
const stats = {
  max: 56.78,
  standard_deviation: 4.34,
  median: 34.54,
  mode: 23.87,
  min: -0.75,
  average: 35.85
};
const half = ({max,min}) => (max + min) / 2.0; 
```

### 字符串格式化

```js
` ${var} world! `
```

### 对象

```js
const createPerson = (name, age, gender) => {
  return {
     name,age,gender };
};
```

### 函数

```js
//对象中函数简化
const obj{
    hello(a) {
        return `hello ${a}`;
    }
}
//导出函数
const add = (x, y) => {
  return x + y;
}
export { add };
//导入
import { add, subtract } from './math_functions.js';
import * as myMathModule from "./math_functions.js";
// export default 只能有一个
export default function add(x,y) => x + y;
```

#### 类

```js
//构造函数
const Vegetable = function(name){
    this.name = name;
}
class Vegetable{
  constructor(name){
    this.name = name;
  }
}
//getter, setter
class Book {
  constructor(author) {
    this._author = author;
  }
  // getter
  get author() {
    return this._author;
  }
  // setter
  set author(updatedAuthor) {
    this._author = updatedAuthor;
  }
}
//不是方法
Book.author = "hello";
```

### Promise

```js
```

https://segmentfault.com/a/1190000015341145

https://www.cnblogs.com/lvdabao/p/es6-promise-1.html

