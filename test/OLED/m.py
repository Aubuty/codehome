#!/usr/bin/python 
# -*- coding: utf-8 -*-

import RPi.GPIO as GPIO

import time
import Adafruit_GPIO.SPI as SPI
import Adafruit_SSD1306

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

# Raspberry Pi pin configuration:
RST = None
# 128x32 display with hardware I2C:
disp = Adafruit_SSD1306.SSD1306_128_64(rst=RST)

# Initialize library.
disp.begin()

# Clear display.
disp.clear()
disp.display()

# Create blank image for drawing.
# Make sure to create image with mode '1' for 1-bit color.
width = disp.width
height = disp.height
image = Image.new('1', (width, height))

# Get drawing object to draw on image.
draw = ImageDraw.Draw(image)

# Load default font.
#font = ImageFont.load_default()

# Alternatively load a TTF font.  Make sure the .ttf font file is in the same directory as the python script!
# Some other nice fonts to try: http://www.dafont.com/bitmap.php
font = ImageFont.truetype('./wp.ttl', 15)

# First define some constants to allow easy resizing of shapes.
padding = 0
top = padding
bottom = height-padding

# Move left to right keeping track of the current x position for drawing shapes.
# 增加 x 值可以将文字向右移动
x = 0
cnt = 0
import subprocess
while 1:
    my_date=time.strftime("%Y-%m-%d",time.localtime())   #获取日期如 2020-09-23
    my_time=time.strftime("%H:%M:%S",time.localtime())   #获取时间如 13:15:03
    my_week=time.strftime("%w",time.localtime())               #获取周几，返回0-6， 0代表周日，1代表周一
    draw.rectangle((0,0,width,height), outline=0, fill=0)
    draw.text((28, 0),   my_time ,  font=font, fill=255)
    draw.text((16, 20),  my_date ,  font=font, fill=255)
    draw.text((88, 40),  "("+my_week+")" ,  font=font, fill=255)
    #draw.text((x, top+16), u'测试'+str(cnt), font=font, fill=100) # 字段前加 u 表示是文字
    
    cnt = cnt+1
    disp.display()
    disp.image(image)
    disp.display()
    #time.sleep(0.01)
    
    
    