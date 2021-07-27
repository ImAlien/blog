```javascript
var vm = new Vue({
        el: '#vue_det', // 代表dom元素的id
        data: {  // 用于定义属性
            site: "菜鸟教程",
            url: "www.runoob.com",
            alexa: "10000"
        },
        methods: { // 用于定义函数
            details: function() {
                return  this.site + " - 学的不仅是技术，更是梦想！";
            }
        }
    })

vm.$el; vm.$data

```

#### 输出

```javascript
//文本插值
<p>{{ message }}</p>
//插入html
<div v-html="message"></div>
//属性值
<div v-bind:class="{'class1': use}">
<a v-bind:href="url">click me</a>
<a :href="url"></a> //缩写
//表达式
{{ message.split('').reverse().join('') }}

//指令
<p v-if="seen">现在你看到我了</p>
//双向数据绑定
<p>{{ message }}</p>
<input v-model="message">
//按钮
 <button v-on:click="reverseMessage">反转字符串</button>
<a @click="doSomething"></a> 
```

#### 过滤器

```javascript
<!-- 在两个大括号中 -->
{{ message | capitalize }}

<!-- 在 v-bind 指令中 -->
<div v-bind:id="rawId | formatId"></div>
```

#### 循环语句

```javascript
<div id="app">
  <ol>
    <li v-for="site in sites">
      {{ site.name }}
    </li>
  </ol>
</div>

<script>
new Vue({
  el: '#app',
  data: {
    sites: [
      { name: 'Runoob' },
      { name: 'Google' },
      { name: 'Taobao' }
    ]
  }
})
</script>

v-for="value in object"
v-for="(value, key) in object"
v-for="(value, key, index) in object"

```

#### 监听属性

主要用于多个属性的联动变化

```javascript

```

#### 键盘监听

```javascript
<!-- 同上 -->
<input v-on:keyup.enter="submit">
<!-- 缩写语法 -->
<input @keyup.enter="submit">
.enter
.tab
.delete (捕获 "删除" 和 "退格" 键)
.esc
.space
.up
.down
.left
.right
.ctrl
.alt
.shift
```

#### 组件

```javascript
Vue.component('runoob', {
  template: '<h1>自定义组件!</h1>'
})
// props：用于传递参数
Vue.component('child', {
  // 声明 props
  props: ['message'],
  // 同样也可以在 vm 实例中像 "this.message" 这样使用
  template: '<span>{{ message }}</span>'
})


```

##### 自定义事件：

组件向外传递数据要使用自定义事件

```javascript
<div id="app">
    <div id="counter-event-example">
      <p>{{ total }}</p>
      <button-counter v-on:increment="incrementTotal"></button-counter>
      <button-counter v-on:increment="incrementTotal"></button-counter>
    </div>
</div>
 
<script>
Vue.component('button-counter', {
  template: '<button v-on:click="incrementHandler">{{ counter }}</button>',
  data: function () {
    return {
      counter: 0
    }
  },
  methods: {
    incrementHandler: function () {
      this.counter += 1
      this.$emit('increment')
    }
  },
})
new Vue({
  el: '#counter-event-example',
  data: {
    total: 0
  },
  methods: {
    incrementTotal: function () {
      this.total += 1
    }
  }
})
</script>
```



