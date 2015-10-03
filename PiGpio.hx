package;

#if cpp
import cpp.Lib;
#elseif neko
import neko.Lib;
#end

class PiGpio {
	
	
	public static function sampleMethod (inputValue:Int):Int {
		return pigpio_sample_method(inputValue);		
	}

	public static function wiringPiSetupGpio ():Void{
		pigpio_wiringPiSetupGpio();	
	}
	
	public static function pinMode ( pin:Int, mode:Int ):Void {
		pigpio_pinMode(pin,mode);
	}

	public static function pinModeAlt ( pin:Int, mode:Int ):Void {
		pigpio_pinModeAlt(pin,mode);
	}

	public static function pullUpDnControl ( pin:Int, mode:Int ):Void {
		pigpio_pullUpDnControl(pin,mode);
	}

 	public static function digitalRead( pin:Int):Int{
 		return pigpio_digitalRead(pin);		
 	}

	public static function digitalWrite ( pin:Int, value:Int ):Void {
		pigpio_digitalWrite(pin,value);
	}
	
	public static function pwmWrite ( pin:Int, value:Int ):Void {
		pigpio_pwmWrite(pin,value);
	}

	public static function analogRead( pin:Int):Int{
		return pigpio_analogRead(pin);	
	}

	public static function analogWrite ( pin:Int, value:Int ):Void {
		pigpio_analogWrite(pin,value);
	}
	
	private static var pigpio_sample_method 	= Lib.load ("pigpio", "pigpio_sample_method", 1);
	
	private static var pigpio_wiringPiSetup 	= Lib.load ("pigpio", "pigpio_wiringPiSetup", 0);
	private static var pigpio_wiringPiSetupSys 	= Lib.load ("pigpio", "pigpio_wiringPiSetupSys", 0);
	private static var pigpio_wiringPiSetupGpio = Lib.load ("pigpio", "pigpio_wiringPiSetupGpio", 0);
	private static var pigpio_wiringPiSetupPhys = Lib.load ("pigpio", "pigpio_wiringPiSetupPhys", 0);

	private static var pigpio_pinMode 			= Lib.load ("pigpio", "pigpio_pinMode", 2);
	private static var pigpio_pinModeAlt 		= Lib.load ("pigpio", "pigpio_pinModeAlt", 2);
	private static var pigpio_pullUpDnControl 	= Lib.load ("pigpio", "pigpio_pullUpDnControl", 2);
	private static var pigpio_digitalRead 		= Lib.load ("pigpio", "pigpio_digitalRead", 1);
	private static var pigpio_digitalWrite 		= Lib.load ("pigpio", "pigpio_digitalWrite", 2);
	private static var pigpio_pwmWrite 			= Lib.load ("pigpio", "pigpio_pwmWrite", 2);
	private static var pigpio_analogRead 		= Lib.load ("pigpio", "pigpio_analogRead", 1);
	private static var pigpio_analogWrite 		= Lib.load ("pigpio", "pigpio_analogWrite", 2);
	
	public static var INPUT 			:Int = 0;
	public static var OUTPUT 			:Int = 1;
	public static var PWM_OUTPUT 		:Int = 2;
	public static var GPIO_CLOCK 		:Int = 3;
	public static var SOFT_PWM_OUTPUT 	:Int = 4;
	public static var SOFT_TONE_OUTPUT 	:Int = 5;
	public static var PWM_TONE_OUTPUT 	:Int = 6;

	public static var LOW 	:Int = 0;
	public static var HIGH 	:Int = 1;

	public static var PUD_OFF 	:Int = 0;
	public static var PUD_DOWN 	:Int = 1;
	public static var PUD_UP 	:Int = 2;

	public static var PWM_MODE_MS 	:Int = 0;
	public static var PWM_MODE_BAL 	:Int = 1;
}