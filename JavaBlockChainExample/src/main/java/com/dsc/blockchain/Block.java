/**
 * Block.java
 * 
 * JavaBlockChainExample Project is a blockchain example 
 * project to test the blockchain concept in Java.
 * 
 * Created by William Williams on 4/07/18.
 * Copyright © 2018 DSC. All rights reserved.
 */

package com.dsc.blockchain;

import java.lang.reflect.Array;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.time.Duration;
import java.time.Instant;
import java.time.format.DateTimeFormatter;
import java.util.Date;

public class Block 
{
	private String transactionPrevHash;
	
	private Integer transactionIndex;
	
	private Long powNonce;
	
	private String transactionData;
	
	private String transactionHash;
	
	private Date transactionTime;
	
	/**
	 * Constructor Method
	 * 
	 * @param transactionIndexIn
	 * @param transactionDataIn
	 */
	public Block(Integer transactionIndexIn, String transactionDataIn)
	{
		this.transactionIndex = transactionIndexIn;
		
		this.transactionData = transactionDataIn;
		
	    this.powNonce = -1L;
	    
	    this.transactionTime = new Date(System.currentTimeMillis());
	}
	
	/**
	 * setTransactionPrevHash Method
	 * 
	 * @param transactionPrevHash
	 */
	public void setTransactionPrevHash(String transactionPrevHash) 
	{
		this.transactionPrevHash = transactionPrevHash;
	}

	/**
	 * getTransactionHash Method
	 * 
	 * @return
	 */
	public String getTransactionHash() 
	{
		return transactionHash;
	}

	/**
	 * generateValidHash Method
	 * 
	 * "Proof of work" algorithm to generate a hash that start with difficulty number of zeros
	 * 
	 * @param difficulty
	 */
	public void generateValidHash(int difficulty)
	{
		Instant validationStartTime = Instant.now();
		
		String[] cString = (String[]) Array.newInstance(String.class, difficulty);
		
		// Create POW string array of zeros (difficulty) long
		for (int i=0; i < difficulty; i++)
		{
			cString[i] = "0";
		}
		
		do
		{
			transactionHash = calculateHash();
		}
		while (!transactionHash.substring(0, difficulty).equals(cString));
		
		Instant validationEndTime = Instant.now();
		
		Duration validationDuration = Duration.between(validationStartTime, validationEndTime);
        
		System.out.print("Block Minded ["+transactionHash+"] StartDT["+ DateTimeFormatter.ISO_INSTANT.format(validationStartTime) +"] EndTime["+ DateTimeFormatter.ISO_INSTANT.format(validationEndTime) +"] Total Duration["+validationDuration.toString()+"]\n\n");
	}
	
	/**
	 * CalculateHash Method
	 * 
	 * @return
	 */
	private String calculateHash()
	{
	    String hashString = null;
	    
	    String retHashString = null;

	    hashString = this.transactionIndex.toString() + this.transactionTime +this.transactionData +this.powNonce + this.transactionPrevHash;
	    
	    MessageDigest mbDigest;
	    
		try 
		{
			mbDigest = MessageDigest.getInstance("SHA-256");
			
			mbDigest.update(hashString.getBytes());
			
			byte[] tempHash = mbDigest.digest();
			
		    StringBuffer hashBuffer = new StringBuffer();

		    for(int i=0;i<tempHash.length;i++)
		    {
		    	hashBuffer.append(Integer.toString((tempHash[i] & 0xff) + 0x100, 16).substring(1));//tempHash[i]);
		    }
			
			retHashString = hashBuffer.toString();
		} 
		catch (NoSuchAlgorithmException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	    
	    return retHashString;
	}
}

