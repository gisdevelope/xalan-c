/*
 * The Apache Software License, Version 1.1
 *
 *
 * Copyright (c) 1999-2002 The Apache Software Foundation.  All rights 
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:  
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xalan" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written 
 *    permission, please contact apache@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com.  For more
 * information on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */
#if !defined(XRESULTTREEFRAG_HEADER_GUARD_1357924680)
#define XRESULTTREEFRAG_HEADER_GUARD_1357924680



// Base header file.  Must be first.
#include <XSLT/XSLTDefinitions.hpp>



#include <XalanDOM/XalanDOMString.hpp>



#if defined(XALAN_AUTO_PTR_REQUIRES_DEFINITION)
#include <XPath/ResultTreeFragBase.hpp>
#endif



#include <Include/XalanAutoPtr.hpp>



// Base class header file.
#include <XPath/NodeRefListBase.hpp>
#include <XPath/XObject.hpp>



#include <XSLT/StylesheetExecutionContext.hpp>



class ResultTreeFrag;



class XALAN_XSLT_EXPORT XResultTreeFrag : public XObject
{
public:

	typedef XObject		ParentType;


	/**
	 * Construct an XResultTreeFrag object from a result tree fragment
	 * 
	 * @param val source result tree fragment.
	 */
	XResultTreeFrag(ResultTreeFragBase&		value);

	/**
	 * Construct an XResultTreeFrag object from another
	 * 
	 * @param source     source XResultTreeFrag
	 * @param deepClone  true to copy all subobjects, default is false
	 */
	XResultTreeFrag(
			const XResultTreeFrag&	source,
			bool					deepClone = false);

	virtual
	~XResultTreeFrag();


	void
	setExecutionContext(StylesheetExecutionContext*		theExecutionContext)
	{
		m_executionContext = theExecutionContext;
	}

	// These methods are inherited from XObject ...

#if defined(XALAN_NO_COVARIANT_RETURN_TYPE)
	virtual XObject*
#else
	virtual XResultTreeFrag*
#endif
	clone(void*		theAddress = 0) const;

	virtual XalanDOMString
	getTypeString() const;
  
	virtual double
	num() const;

	virtual bool
	boolean() const;

	virtual const XalanDOMString&
	str() const;

	virtual void
	str(
			FormatterListener&	formatterListener,
			MemberFunctionPtr	function) const;

	virtual void
	str(XalanDOMString&	theBuffer) const;

	virtual double
	stringLength() const;

	virtual const ResultTreeFragBase&
	rtree() const;

	virtual const NodeRefListBase&
	nodeset() const;

	virtual void
	ProcessXObjectTypeCallback(XObjectTypeCallback&		theCallbackObject);

	virtual void
	ProcessXObjectTypeCallback(XObjectTypeCallback&		theCallbackObject) const;

	/**
	 * Release the ResultTreeFrag held by the instance.
	 */
	ResultTreeFragBase*
	release();

	/**
	 * Change the value of an XResultTreeFrag
	 *
	 * @param theValue The new value.
	 */
	void
	set(ResultTreeFragBase*		theValue);

protected:

	virtual void 
	dereferenced();

private:

	// Data members...
	ResultTreeFragBase*				m_value;	

	StylesheetExecutionContext*		m_executionContext;

	mutable XalanDOMString			m_cachedStringValue;

	mutable double					m_cachedNumberValue;
};



#endif	// XRESULTTREEFRAG_HEADER_GUARD_1357924680
