# PJTコマンドの使用方法
```
% git clone git@github.com:ImadaKakeru/pjt_command.git
% cd pjt_command
% make
% ./pjt [options] [filename]
```
# PJTコマンドの仕様
## 1.ファイルまたは標準入力から入力を読み込み、2分探索木を作成する。
- コマンドラインに1つ以上の引数 (後述するオプションを除く) が与えられた場合、それらを入力ファイルとして順に読み込む。
- 空ファイルを読み込んだ場合は読み込み ERROR(NULL 判定) が出ない限り標準入力からの読み込みはしない。
- 読み込み ERROR の場合はエラーを出力するようにする。
- 引数 (後述するオプションを除く) が1つも存在しない場合、標準入力からの入力を読み込む。
```
%cat hoge.txt
aaa
ccc
bbb dddd ss
as
asfas
asds
bbb
```

## 入力から単語を順に切り出し、2 分探索木に格納する
各ノードの子の数が高々2となるような順序木を2分木と呼ぶ。
各ノードのデータが次の条件を満たす2分木を特に2分探索木と呼ぶ。
### (条件)
- あるノードから見て、左側の子ノードおよびその子孫ノードのデータ全てが自身が持つデータ (文
字列) より小さい
- あるノードから見て、右側の子ノードおよびその子孫ノードのデータ全てが自身が持つデータ以上の大きさを持つ。

![二分探索木](https://github.com/ImadaKakeru/pjt_command/assets/150673391/b5d7be53-a1ae-45af-9543-2d571e18bb80)

## 作成した2分探索木に対して、コマンドラインで指定されるオプションに応じた処理を実行する
### オプションなし（デフォルトの操作）
引数に与えた文字列を2分探索木として確保し、間順走査で表示する。

#### -p[number] (0:全順走査 1:間順走査 2:後順走査)
生成した2分探索木の各文字列を指定された走査順で表示する。引数が存在しない場合は`number = 1`とみなす。
##### -pオプションを指定した場合の一例
```
% cat 1abc.txt
defg
abc
zzzz
whasiuf
y
goo
pin
hanpen

% ./pjt -p 1 1abc.txt
---BinSTree---
abc
defg
goo
hanpen
pin
whasiuf
y
zzzz
```

### -s /match/repalce/
生成した2分探索木の各ノードが持つ文字列について、部分文字列`match`を含む場合、文字列を`replace`に置換する。
`replace`に`space`が1つでも含まれる場合はオプションエラーを返す。
また、`replace`が空文字の場合は、部分文字列`match`を削除する。
#### -s オプションを指定した場合の例
```
%cat testcase/subst_sample.txt
defg
hoge
zzzz
defanddef
%./pjt -s /def/apple/ testcase/subst_sample.txt
---BinSTree---
appleandapple
appleg
hoge
zzzz
```
#### -s /match//とした場合の例
```
%cat testcase/u_sample.txt
hoge
hage
hoge
hage
onemu
%./pjt -s /ge// testcase/u_sample.txt
---BinSTree---
ha
ha
ho
ho
onemu
```


### -u
2分探索木に同じ文字列が複数存在する場合1つのみを出力する。引数は取らず、走査順は`-p`オプショ
ンに従う。
#### -u オプションを指定した場合の例
```
%./pjt -u testcase/u_sample.txt
---BinSTree---
hage
hoge
onemu
```
### -r /removematch/delall/
2 分探索木から与えられた文字列`removematch`を持つノードを削除する。`delall`が真 (0) であれば、全
て削除し、偽 (0 以外) であれば`root`ノードから一番近いノードのみを削除する。
#### -r オプションを指定した場合の例
```
%./pjt -r /hoge/0/ testcase/u_sample.txt
---BinSTree---
hage
hage
onemu
%./pjt -r /hoge/1/ testcase/u_sample.txt
---BinSTree---
hage
hage
hoge
onemu
```

### オプション補足
#### 入力ファイルは option の後にしか存在しない設定とする。
```
(正) %./pjt -r /match/delall/ -u -p 0 -s /match/replace/ file1 file2 file3
%./pjt -p 0 -u file1
(誤) %./pjt -r /match/delall/ -u file1 file2 file3 -p 0 -s /match/replace/
%./pjt -p file1 -u file2
```

#### -s -r オプションが重複する場合
`-s`,`-r`オプションに関しては複数回実行可能である。また、その際与えられたoptionの順番に応
じて実行する。
```
%./pjt -s /ge/go/ -r /hogo/1/ -s /hogo/banana/ testcase/u_sample.txt
---BinSTree---
banana
hago
hago
onemu
```
#### -s -rオプションにより、ノードが消失する場合
`-s`,`-r`オプションによって、ノードが全てなくなった場合はなくなったことを表示する。
```
%./pjt -r /hoge/0/
---standard input---
hoge
hoge
hoge
---BinSTree---
There is no node
```
### オプションやファイル名が不適切な場合
オプションやファイル名が不適切な場合はエラーを出力する。また、何が不適切だったのかをエラーメッセージとして出力する。
```
%./pjt -r /a/
usage:ERROR (incorrect -r format follow -r /rmvmatch/delall/)
%./pjt -d
usage:ERROR (options are invalid)
%./pjt non_existing_file.txt
usage:ERROR (File is NULL(read file))
```
