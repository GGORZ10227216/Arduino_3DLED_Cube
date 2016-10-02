<h1>Arduino 3D LED燈</h1>

<img src="/galley/3.jpg" />

<p>這是一個利用74595搭配Arduino Mega2560所製作出的暑期訓練專題</p>
<p>你可以在 https://www.youtube.com/watch?v=W8xdciFAuEY 看到他實際運作的影片</p>
<p>理論製作時間(單人): 3~4周</p>
<br>
<p>這個專題是我進入自控社後第一次擔任組長所指導的暑訓專題，當初為了要節省控制LED的記憶體用量</p>
<p>使用了Bitwise operator而不是512個boolean來控制燈泡狀態，所以在閱讀上難度稍高。</p>
<p>另外，若使用port manipulation來控制GPIO的話，理論上速度可以在上升，只是程式碼會變成只有mega可用</p>
<br>
<h3>材料</h3>
<p>74HC595 * 8</p>
<p>任意顏色的LED * 512</p>
<p>Arduino Mega2560(若搭配74138則可進一步將電路移至Uno上)</p>
<p>220R電阻、杜邦線依需求調整</p>
