'''插入多条数据'''
import pymysql
#打开数据库连接，不指定数据库
conn=pymysql.connect(host='localhost',user='root',passwd='123456')
conn.select_db('smartdata')
#获取游标
cur=conn.cursor()

#另一种插入数据的方式，通过字符串传入值
insert=cur.execute("insert into data values(1,'',18)")
print('添加语句受影响的行数：',insert)

cur.close()
conn.commit()
conn.close()
print('sql执行成功')
