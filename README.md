# PJTコマンドの使用方法
```
% git clone git@github.com:ImadaKakeru/pjt_command.git
% cd pjt_command
% make
% ./pjt [options] [filename]
```

#  PJTオプション
## オプションなし（デフォルトの操作）
引数に与えた文字列を2分探索木として確保し、間順走査で表示する。

## -p[number] (0:全順走査 1:間順走査 2:後順走査)
生成した2分探索木の各文字列を指定された走査順で表示する。引数が存在しない場合は`number = 1`とみなす。
### -pオプションを指定した場合の一例
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

##
##
##
