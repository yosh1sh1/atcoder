## 解法

### BFS

* map で遷移した状態を保持
  * 今回であれば、遷移回数が欲しいため map が適していた
  * モノによっては set でもよさそう
* queue で遷移する状態を管理

### 難しかった点

* Nが小さい → 全探索だろう とは思えても、探索のやり方が思いつかない…
  * BFSを使用するという考えが出てこない
    * これは仕方ない。少しずつ身につけれればよい。
    * 回答で「BFSを使用します」となってても正直 ? だった
    * BFSを調べても、遷移の仕方で初期状態を S で持つってやり方が全く浮かばなかった
  * 動画での解説を見て理解できたし、BFSの記述は結構楽ということが分かってよかった…あまり身構える必要なさそう…
  