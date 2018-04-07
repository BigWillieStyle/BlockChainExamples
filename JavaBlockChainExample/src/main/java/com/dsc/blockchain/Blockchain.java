/**
 * Blockchain.java
 * 
 * JavaBlockChainExample Project is blockchain a example 
 * project to test the blockchain concept in Java.
 * 
 * Created by William Williams on 4/07/18.
 * Copyright © 2018 DSC. All rights reserved.
 */


package com.dsc.blockchain;

import java.util.Vector;

public class Blockchain 
{
    private static final int DIFFICULTY = 6;
    
    private Vector<Block> vChain;
    
    /**
     * Constructor
     */
    public Blockchain()
    {
    	vChain = new Vector<Block>();
    	
    	vChain.addElement(new Block(0,"Genesis Block"));
    }
    
    /**
     * addBlock Method
     * 
     * @param newBlock
     */
	public void addBlock(Block newBlock)
	{
		newBlock.setTransactionPrevHash(getLastBlock().getTransactionHash());
		
		newBlock.generateValidHash(DIFFICULTY);
		
		vChain.addElement(newBlock);
	}
	
	/**
	 * getLastBlock Method
	 * 
	 * @return
	 */
	private Block getLastBlock()
	{
		return vChain.lastElement();
	}
}

