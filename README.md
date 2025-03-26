微控制器：STM32F446RE

軟體：STM32CubeMX, STM32CubeIDE, Matlab, WCHSerialPort

其他硬體：L298N馬達驅動版、祥儀12V直流馬達（內建編碼器）、麵包板

控制目標：完成馬達的定點控制

設置STM32CubeMX如下：
1. 使用三個定時器TIM2、TIM3和TIM4，功能分別為PWM設置、編碼器模式設置以及執行1毫秒中斷程序。
2. 設置兩個GPIO為輸出模式，分別驅動直流馬達的正、反轉。
3. 設置一組uart接口，用於傳輸數據到PC端。

Step:
1. 開啟TIM2通道1的PWM模式、TIM3全通道的編碼器模式以及TIM4的中斷功能。
2. 在TIM4的callback function執行控制流程。
3. 將計算結果使用一階低通濾波器過濾雜訊，並擷取前5秒的data，將5001筆資料存儲於myData這個buffer中。
4. 使用uart將buffer儲存的結果輸出至PC，並以WCHSerialPort這個serial工具儲存成.txt檔案。
5. 利用matlab解析.txt檔案，並輸出馬達真實的響應。
