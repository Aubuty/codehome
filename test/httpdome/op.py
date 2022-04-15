#coding=UTF-8
import requests
  
url = r'https://netocr.com/api/facerecog.do' #需修改为对应产品接口url
key = r'QiJwjne3hkv6ka4MV63p4v'
secret = r'dbc950e51ec14fc1ba0d940e27a720c9'
typeId = 21  #产品类型需修改为对应产品类型值,详见文档说明
rFormat = r'xml'
#要上传的文件
file1 = {'file1': open('./liuxu.jpg', 'rb'),'file2':open('./2.jpg','rb')}

# post携带的数据           
data = {'key':key, 'secret':secret, 'typeId':typeId, 'format':rFormat}
 
  
r = requests.post(url, files=file1, data = data)
print(r.text)