/**
 * Main.java
 * 
 * JavaBlockChainExample Project is a blockchain example 
 * project to test the blockchain concept in Java.
 * 
 * Created by William Williams on 4/07/18.
 * Copyright © 2018 DSC. All rights reserved.
 */
package com.dsc.blockchain;

import java.time.Duration;
import java.time.Instant;
import java.time.format.DateTimeFormatter;

public class Main {

	public static void main(String[] args) 
	{
		String transactionData;
		
		Blockchain blockchain = new Blockchain();
		
		Instant processStartTime = Instant.now();
		
		for (int i=1; i < 50; i++)
		{
			transactionData = "Block "+i+" Data";
			
			blockchain.addBlock(new Block(i,transactionData));
		}

		Instant processEndTime = Instant.now();
		
		Duration duration = Duration.between(processStartTime, processEndTime);
		
		System.out.print("Process start time ["+DateTimeFormatter.ISO_INSTANT.format(processStartTime)+"] Process End Time["+ DateTimeFormatter.ISO_INSTANT.format(processEndTime)+"] Total Process Time"+duration.toString()+"]");
	}

}
